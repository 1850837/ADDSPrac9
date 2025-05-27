#ifndef DOCUMENTMANAGER_H
#define DOCUMENTMANAGER_H

#include <string>
#include <map>
#include "Document.h"
#include "Patron.h"

class DocumentManager {
    private:
    //three maps, one for document name to document pointer
    //one for document id to document pointer
    //one for patron id to patron pointer

    std::map<std::string, Document*> docNameMap;
    std::map<int, Document*> docIDMap;
    std::map<int, Patron*> patronIDMap;

    public:
    DocumentManager();
    void addDocument(std::string name, int id, int license_limit);
    void addPatron(int patronID);
    int search(std::string name); // returns docid if name is in the document collection or 0 if the name is not in the collection
    bool borrowDocument(int docid, int patronID);  // returns true if document is borrowed, false if it can not be borrowed 
                                                   //(invalid patronid or the number of copies current borrowed has reached the license limit)
    void returnDocument(int docid, int patronID);
};

#endif