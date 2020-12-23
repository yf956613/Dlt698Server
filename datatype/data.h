#ifndef DLT698_DATA_H
#define DLT698_DATA_H

#include "dlt698proctol.h"
#include <unordered_map>
#include <list>

namespace Dlt698 {

class Data : public Dlt698Proctol
{
public:
    Data(Data *parent = nullptr);
    Data(Data &other, Data *parent = nullptr);

    eDataType dataType() const;
    void setDataType(const eDataType &dataType);

    Data* decodeProxy(const vector<BYTE> &res, size_t &pos);
    void encodeProxy(vector<BYTE> &res);

    list<Data *> childs() const;
    const list<Data *>& childs();

    Data *getParent() const;
    void setParent(Data *parent);

    void childsClear();

    virtual Data* clone(Data *parent = nullptr);
    virtual Data& operator=(Data &other);
    virtual ~Data();

    static void addNameType(const std::string &name, eDataType type);
    static eDataType getTypeByName(const std::string& name);

private:
    eDataType m_dataType;

    Data* m_parent;

    list<Data*> m_childs;

    static unordered_map<std::string, eDataType> m_nameType;

};

template<typename T>
T& dynamicCopy(T &self, Data &other) {
    T* temp = dynamic_cast<T*>(&other);
    if(temp != NULL) {
        self = *temp;
    }
    return self;
}

}

#endif
