#include <vector>
#include <string>
#include <iostream>

class IR
{
public:
    std::vector<std::string> args;

    IR(std::vector<std::string> args)
    {
        this->args = args;
    }

    virtual std::string str()
    {
        return "nope";
    };
};

class LABEL_IR : public IR
{
public:
    LABEL_IR(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return "LABEL " + args[0] + " :";
    }
};

class FUNCTION_IR : public IR
{
public:
    FUNCTION_IR(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return "FUNCTION " + args[0] + " :";
    }
};
class ASSIGN_IR : public IR
{
public:
    ASSIGN_IR(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return args[0] + " := " + args[1];
    }
};
class ADD_IR : public IR
{
public:
    ADD_IR(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return args[0] + " := " + args[1] + " + " + args[2];
    }
};
class SUB_IR : public IR
{
public:
    SUB_IR(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return args[0] + " := " + args[1] + " - " + args[2];
    }
};
class MUL_IR : public IR
{
public:
    MUL_IR(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return args[0] + " := " + args[1] + " * " + args[2];
    }
};
class DIV_IR : public IR
{
public:
    DIV_IR(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return args[0] + " := " + args[1] + " / " + args[2];
    }
};
class REF_IR : public IR
{
public:
    REF_IR(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return args[0] + " := &" + args[1];
    }
};
class RDEREF_IR : public IR
{
public:
    RDEREF_IR(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return args[0] + " := *" + args[1];
    }
};
class LDEREF_IR : public IR
{
public:
    LDEREF_IR(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return "*" + args[0] + " := " + args[1];
    }
};
class GOTO_IR : public IR
{
public:
    GOTO_IR(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return "GOTO " + args[0];
    }
};
class IF_IR : public IR
{
public:
    IF_IR(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return "IF " + args[0] + " " + args[1] + " " + args[2] + " GOTO " + args[3];
    }
};
class RET_IR : public IR
{
public:
    RET_IR(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return "RET " + args[0];
    }
};
class DEC_IR : public IR
{
public:
    DEC_IR(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return "DEC " + args[0] + " " + args[1];
    }
};
class PARAM_IR : public IR
{
public:
    PARAM_IR(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return "PARAM " + args[0];
    }
};
class ARG_IR : public IR
{
public:
    ARG_IR(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return "ARG " + args[0];
    }
};
class CALL_IR : public IR
{
public:
    CALL_IR(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return args[0] + " := " + "CALL " + args[1];
    }
};
class READ_IR : public IR
{
public:
    READ_IR(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return "READ " + args[0];
    }
};
class WRITE_IR : public IR
{
public:
    WRITE_IR(std::vector<std::string> args) : IR(args) {}
    virtual std::string str()
    {
        return "WRITE " + args[0];
    }
};
