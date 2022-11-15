// GenericDocument.cpp : � COMPL�TER

#include "GenericDocument.h"

GenericDocument::GenericDocument(std::string name, std::string dateTime, std::string description)
    :AbsDocument(name, dateTime)
{
}

GenericDocument* GenericDocument::clone() const
{
    return new GenericDocument(*this);
}