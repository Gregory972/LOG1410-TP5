#include <string>

#include "Directory.h"
#include "AbsDocument.h"

int Directory::m_indent = 0;

Directory::Directory(std::string name)
	: AbsDirectoryComponent(name)
{
}

Directory::Directory(const Directory& mdd)
	: AbsDirectoryComponent(mdd.m_name)
{
	// � compl�ter pour copier tous les �l�ments contenus dans le r�pertoire
	for (auto&& element = mdd.cbegin(); element != mdd.cend(); element++) {
		addDirectoryComponent(*element);
	}
}

Directory* Directory::clone(void) const
{
	// � compl�ter pour construire un nouvel objet Directory en appelant le constructeur de copie
	return new Directory(*this); // � remplacer
}

AbsDirectoryComponent& Directory::addDirectoryComponent(const AbsDirectoryComponent& member)
{
	// � compl�ter pour construire par clonage une copie de l'objet re�u en param�tre
	// et l'ins�rer dans le conteneur de documents. On retourne une r�f�rence � l'objet
	// qui vient d'�tre ins�r� dans le conteneur.
	m_documents.push_back(DirectoryComponentPtr(member.clone()));

	return *m_documents.back(); // � remplacer 
}

DirectoryComponentIterator Directory::begin()
{
	return m_documents.begin();
}

DirectoryComponentIterator_const Directory::cbegin() const
{
	return m_documents.cbegin();
}

DirectoryComponentIterator_const Directory::cend() const
{
	return m_documents.cend();
}

DirectoryComponentIterator Directory::end()
{
	return m_documents.end();
}

void Directory::deleteDirectoryComponent(DirectoryComponentIterator_const child)
{
	// � compl�ter pour �liminer du r�pertoire l'�l�ment auquel r�f�re l'it�rateur
	m_documents.erase(child);
}

void Directory::deleteAllComponents(void)
{
	// � compl�ter pour �liminer tous les �l�ments du r�pertoire
	for (auto&& element = m_documents.cbegin(); element != m_documents.cend(); element++) {
		deleteDirectoryComponent(element);
	}
}

const AbsDocument* Directory::findDocument(std::string productName) const
{
	// � compl�ter pour it�rer sur les �l�ments contenus dans le r�pertoire � la recherche d'un document
	// portant le nom re�u en argument. Si aucun document n'est trouv�, on retourne nullptr
	const AbsDocument* foundDocument = nullptr;

	for (auto&& element = m_documents.cbegin(); element != m_documents.cend(); element++) {
		if (foundDocument = (*element)->findDocument(productName)) {
			break;
		}
		else {
			foundDocument = foundDocument;
		}
	}

	return foundDocument;
}

std::ostream& Directory::printToStream(std::ostream& o) const
{
	// � compl�ter pour imprimer sur un stream une cat�gorie et son contenu
	o << "Document : " << m_name << "\n";

	for (auto&& element : m_documents)
	{
		m_indent += 1;
		indent(o) << *element << "\n";
		m_indent -= 1;
	}
	return o;
}

std::ostream& Directory::indent(std::ostream& o) const
{
	for (int i = 0; i < m_indent; ++i)
		o << '\t';
	return o;
}