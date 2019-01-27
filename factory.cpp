#include <string>
#include <ostream>
#include <iostream>

using namespace std;

struct Person
{
    int id;
    string name;

public:
    friend ostream &operator<<(ostream &os, const Person &person) {
        os << "id: " << person.id << " name: " << person.name;
        return os;
    }
};

class PersonFactory
{
    int id = -1;
public:
    int getId() const {
        return id;
    }

    Person create_person(const string& name)
    {
        id++;
        return {id, name};
    }
};

int main()
{
    unique_ptr<PersonFactory> p(new PersonFactory);
    p -> create_person("Bob");
    p -> create_person("Candice");

    cout << p -> getId() << endl;

    return 0;
}
