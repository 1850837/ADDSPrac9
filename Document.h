#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>

class Document {
    friend class DocumentManager;

    private:
    std::string newName;
    int newIdentifier;
    int newLimit;

    public:
    Document(std::string name, int identifier, int limit);
};

#endif