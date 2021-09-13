#!/usr/bin/env python3
""" SoLoud D wrapper generator """

import soloud_codegen

fo = open("../glue/soloud.d", "w")


C_TO_D_TYPES = {
    "string":"string",
    "int":"int",
    "void":"void",
    "const char *":"const(char)*",
    "char *":"char*",
    "unsigned int":"uint",
    "float":"float",
    "double":"double",
    "float *":"float[]",
    "File *":"SoloudObject",
    "const unsigned char *":"ubyte*",
    "unsigned char *":"ubyte*",
    "unsigned char":"ubyte",
    "short *":"short[]"
}

for soloud_type in soloud_codegen.soloud_type:
    C_TO_D_TYPES[soloud_type + " *"] = "SoloudObject"

def has_ex_variant(funcname):
    """ Checks if this function has an "Ex" variant """
    if funcname[-2::] == "Ex":
        # Already an Ex..
        return False
    for func in soloud_codegen.soloud_func:
        if func[1] == (funcname + "Ex"):
            return True
    return False

fo.write("""
// SoLoud wrapper for D
// This file is autogenerated; any changes will be overwritten

module soloud;

pure @safe nothrow @nogc:

private struct SoloudObject
{
    public int* objhandle;
}

""")

# Forward declare ALL THE CLASSES
for soloud_type in soloud_codegen.soloud_type:
    #fo.write("public class %s;\n"%(soloud_type))
    pass


# Since there's no reason to use the "raw" data anymore,
# skip generating the enum dictionary
#
#fo.write("# Enumerations\n")
#fo.write("soloud_enum = {\n")
#first = True
#for x in soloud_codegen.soloud_enum:
#    if first:
#        first = False
#    else:
#        fo.write(",\n")
#    fo.write('"' + x + '": ' + str(soloud_codegen.soloud_enum[x]))
#fo.write("\n}\n")

fo.write("\n")
# fo.write("# Raw DLL functions\n")
# for x in soloud_codegen.soloud_func:
#     fo.write(x[1] + ' = soloud_dll.' + x[1] + '\n')
#     fo.write(x[1] + '.restype = ' + C_TO_D_TYPES[x[0]] + '\n')
#     fo.write(x[1] + '.argtypes = [')
#     first = True
#     for y in x[2]:
#         if len(y) > 0:
#             if first:
#                 first = False
#             else:
#                 fo.write(", ")
#             fo.write(fudge_types(y[0]))
#     fo.write(']\n')
#     fo.write('\n')
#
#################################################################
#
# oop
#

#    class classname : SoloudObject
#    {
#    public const int CONSTANT = 3;
#    [DllImport("soloud_x86.dll", CallingConvention = CallingConvention.Cdecl)]
#    internal static extern int classname_foobar(...
#    public int foobar(...
#    {
#        classname_foobar(...
#    }
#

def fix_default_param(defparam, classname):
    """ 'fixes' default parameters from C to what python expectes """
    if (classname + '::') == defparam[0:len(classname)+2:]:
        return defparam[len(classname)+2::]
    #if defparam[len(defparam)-1] == "f":
    #    return defparam[0:len(defparam)-1]
    return defparam

def external_pointer_fix(param):
    if param == "SoloudObject":
        return "int*"
    return param

function_decls = ""

for x in soloud_codegen.soloud_type:
    first = True
    for y in soloud_codegen.soloud_func:
        if (x + "_") == y[1][0:len(x)+1:]:
            if first:
                # Declare creator and destroyer
                function_decls += ('private static extern(C) int* %s_create();\n'%(x))
                function_decls += ('private static extern(C) int* %s_destroy(int* aObjHandle);\n'%(x))

                fo.write('\n')
                fo.write('public struct %s\n{\n'%(x))
                fo.write('pure @safe nothrow @nogc:\n')
                for z in soloud_codegen.soloud_enum:
                    if z[0:len(x)+1] == x.upper()+'_':
                        s = str(soloud_codegen.soloud_enum[z])
                        fo.write('\tpublic enum %s = %s;\n'%(z[len(x)+1::], s))
                fo.write('\n')

                fo.write('\tpublic SoloudObject soloudObject;\n')
                fo.write('\talias soloudObject this;\n\n')
                fo.write('\tpublic static create()\n\t{\n')
                fo.write('\t\treturn %s(SoloudObject(%s_create()));\n'%(x, x))
                fo.write('\t}\n\n')
                fo.write('\t~this()\n\t{\n')
                fo.write('\t\t%s_destroy(objhandle);\n'%(x))
                fo.write('\t}\n\n')

                first = False
            funcname = y[1][len(x)+1::]
            # If the function has the name "Ex", remove the subfix
            if funcname[-2::] == "Ex":
                funcname = funcname[:len(funcname)-2]
            # Skip generating functions that have an Ex variant
            if funcname == "create" or funcname == "destroy" or has_ex_variant(y[1]):
                pass # omit create/destroy, handled by __exit__ / close
            else:
                ret = C_TO_D_TYPES[y[0]]
                function_decls += ('private static extern(C) %s %s(int* aObjHandle'%(ret, y[1]))
                for z in y[2]:
                    if len(z) > 1:
                        if z[1] == 'a'+x:
                            pass # skip the 'self' pointer
                        else:
                            function_decls += ', '
                            function_decls += external_pointer_fix(C_TO_D_TYPES[z[0]]) + ' ' + z[1]
                function_decls += ');\n'

                fo.write('\tpublic %s %s('%(C_TO_D_TYPES[y[0]], funcname))
                firstparm = True
                for z in y[2]:
                    if len(z) > 1:
                        if z[1] == 'a'+x:
                            pass # skip the 'self' pointer
                        else:
                            if firstparm:
                                firstparm = False
                            else:
                                fo.write(', ')
                            fo.write(C_TO_D_TYPES[z[0]] + ' ' + z[1])
                            if len(z) > 2:
                                fo.write(' = ' + fix_default_param(z[2], x))
                fo.write(')\n\t{\n')
                fo.write('\t\t')
                if y[0] == 'void':
                    pass
                else:
                    fo.write('return ')
                fo.write(y[1] + '(objhandle')
                for z in y[2]:
                    if len(z) > 1:
                        if z[1] == 'a'+x:
                            pass # skip the 'self' pointer
                        else:
                            fo.write(', ')
                            fudged_type = C_TO_D_TYPES[z[0]]
                            if fudged_type == 'SoloudObject':
                                fo.write(z[1] + '.objhandle')
                            else:
                                fo.write(z[1])
                fo.write(');\n')
                fo.write('\t}\n\n')
    if not first:
        fo.write('}\n')

fo.write(function_decls)

fo.close()

print("soloud.d generated")
