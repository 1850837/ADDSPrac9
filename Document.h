#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>

class Document {
    friend class DocumentManager;

    private:
    std::string name;
    int identifier;
    int limit;

    public:
    // Document();
    Document(std::string name, int identifier, int limit);
};

#endif