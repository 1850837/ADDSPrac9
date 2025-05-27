#include "DocumentManager.h"

DocumentManager::DocumentManager(){

}

void DocumentManager::addDocument(std::string name, int id, int license_limit){
    Document* doc = new Document(name, id, license_limit);
    docNameMap.insert(std::pair<std::string, Document*>(name, doc));
    docIDMap.insert(std::pair<int, Document*>(id, doc));

    return;
}

void DocumentManager::addPatron(int patronID){
    Patron* pat = new Patron(patronID);
    patronIDMap.insert(std::pair<int, Patron*>(patronID, pat));

    return;
}

int DocumentManager::search(std::string name){
    std::map<std::string, Document*>::iterator doc = docNameMap.find(name);

    //case where it doesn't find it
    if (doc == docNameMap.end()){
        return 0;
    }

    //case where it does find it
    return doc->second->newIdentifier;
}

bool DocumentManager::borrowDocument(int docid, int patronID){
    //search for the document with that id
    std::map<int, Document*>::iterator doc = docIDMap.find(docid);

    //case for document not found
    if (doc == docIDMap.end()){
        return false;
    }

    //check if there are copies available
    if (doc->second->newLimit <= 0){
        return false;
    }
    
    //check that the patron is real
    std::map<int, Patron*>::iterator pat = patronIDMap.find(patronID);
    if (pat == patronIDMap.end()){
        return false;
    }

    //borrow the document
    doc->second->newLimit = doc->second->newLimit - 1;    //take the number down one
    return true;
}
    
void DocumentManager::returnDocument(int docid, int patronID){
    //search for the document with that id
    std::map<int, Document*>::iterator doc = docIDMap.find(docid);

    //case for document not found
    if (doc == docIDMap.end()){
        return;
    }
    
    //check that the patron is real
    std::map<int, Patron*>::iterator pat = patronIDMap.find(patronID);
    if (pat == patronIDMap.end()){
        return;
    }

    //borrow the document
    doc->second->newLimit = doc->second->newLimit + 1;    //take the number down one
    return;
}