#include <string>
#include <ostream>
#include <iostream>
#include <vector>

using namespace std;

class ClassElement
{
private:
    string name, type;
public:
    ClassElement(const string &name, const string &type) : name(name), type(type) {}

    const string &getName() const {
        return name;
    }

    const string &getType() const {
        return type;
    }
};

class CodeBuilder
{
private:
    string class_n;
    vector<ClassElement> members;
public:
    explicit CodeBuilder(const string& class_name)
    {
        class_n = class_name;
    }

    string get_class_name() const{ return class_n; }

    CodeBuilder& add_field(const string& name, const string& type)
    {
        members.emplace_back(ClassElement(name, type));
        return *this;
    }

    friend ostream& operator<<(ostream& os, const CodeBuilder& obj)
    {
        os << "class " << obj.get_class_name() << endl << "{" << endl;

        for(auto &m: obj.members)
        {
            os << "  " << m.getType() << " " << m.getName() << ";" << endl;
        }

        os << "};";
        return os;
    }
};

int main()
{
    CodeBuilder cb = CodeBuilder{"Person"}.add_field("name", "string")
            .add_field("age", "int");

    cout << cb << endl;

    return 0;
}
