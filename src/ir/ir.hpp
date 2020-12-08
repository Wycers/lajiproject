#include <vector>
#include <string>
#include <iostream>

struct IR {
    std::vector<std::string> args;

    IR(std::vector<std::string> args) {
        this->args = args;
    }

    virtual std::string str() {
        return "nope";
    };
};

struct LABEL_IR : public IR {
    LABEL_IR(std::vector<std::string> args) : IR(args) {}

    virtual std::string str() {
        return "LABEL " + args[0] + " :";
    }
};

struct FUNCTION_IR : public IR {
    FUNCTION_IR(std::vector<std::string> args) : IR(args) {}

    virtual std::string str() {
        return "FUNCTION " + args[0] + " :";
    }
};

struct ASSIGN_IR : public IR {
    ASSIGN_IR(std::vector<std::string> args) : IR(args) {}

    virtual std::string str() {
        return args[0] + " := " + args[1];
    }
};

struct ADD_IR : public IR {
    ADD_IR(std::vector<std::string> args) : IR(args) {}

    virtual std::string str() {
        return args[0] + " := " + args[1] + " + " + args[2];
    }
};

struct SUB_IR : public IR {
    SUB_IR(std::vector<std::string> args) : IR(args) {}

    virtual std::string str() {
        return args[0] + " := " + args[1] + " - " + args[2];
    }
};

struct MUL_IR : public IR {
    MUL_IR(std::vector<std::string> args) : IR(args) {}

    virtual std::string str() {
        return args[0] + " := " + args[1] + " * " + args[2];
    }
};

struct DIV_IR : public IR {
    DIV_IR(std::vector<std::string> args) : IR(args) {}

    virtual std::string str() {
        return args[0] + " := " + args[1] + " / " + args[2];
    }
};

struct REF_IR : public IR {
    REF_IR(std::vector<std::string> args) : IR(args) {}

    virtual std::string str() {
        return args[0] + " := &" + args[1];
    }
};

struct RDEREF_IR : public IR {
    RDEREF_IR(std::vector<std::string> args) : IR(args) {}

    virtual std::string str() {
        return args[0] + " := *" + args[1];
    }
};

struct LDEREF_IR : public IR {
    LDEREF_IR(std::vector<std::string> args) : IR(args) {}

    virtual std::string str() {
        return "*" + args[0] + " := " + args[1];
    }
};

struct GOTO_IR : public IR {
    GOTO_IR(std::vector<std::string> args) : IR(args) {}

    virtual std::string str() {
        return "GOTO " + args[0];
    }
};

struct IF_IR : public IR {
    IF_IR(std::vector<std::string> args) : IR(args) {}

    virtual std::string str() {
        return "IF " + args[0] + " " + args[1] + " " + args[2] + " GOTO " + args[3];
    }
};

struct RET_IR : public IR {
    RET_IR(std::vector<std::string> args) : IR(args) {}

    virtual std::string str() {
        return "RET " + args[0];
    }
};

struct DEC_IR : public IR {
    DEC_IR(std::vector<std::string> args) : IR(args) {}

    virtual std::string str() {
        return "DEC " + args[0] + " " + args[1];
    }
};

struct PARAM_IR : public IR {
    PARAM_IR(std::vector<std::string> args) : IR(args) {}

    virtual std::string str() {
        return "PARAM " + args[0];
    }
};

struct ARG_IR : public IR {
    ARG_IR(std::vector<std::string> args) : IR(args) {}

    virtual std::string str() {
        return "ARG " + args[0];
    }
};

struct CALL_IR : public IR {
    CALL_IR(std::vector<std::string> args) : IR(args) {}

    virtual std::string str() {
        return args[0] + " := " + "CALL " + args[1];
    }
};

struct READ_IR : public IR {
    READ_IR(std::vector<std::string> args) : IR(args) {}

    virtual std::string str() {
        return "READ " + args[0];
    }
};

struct WRITE_IR : public IR {
    WRITE_IR(std::vector<std::string> args) : IR(args) {}

    virtual std::string str() {
        return "WRITE " + args[0];
    }
};


typedef std::vector<IR *> IRList;
