#ifndef PATRON_H
#define PATRON_H

class Patron {
    friend class DocumentManager;

    private:
    int patronID;

    public:
    Patron(int patronID);
};

#endif