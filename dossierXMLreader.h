#ifndef DOSSXMLREAD_H
#define DOSSXMLREAD_H

#include "dossier.h"

namespace INSCRIPTIONS{
    //class pour lire et récupérer un fichier XML avec le dossier
    class XmlStreamReader
    {
    public:
        XmlStreamReader(Dossier* doss, Cursus *rootCursus);
        Cursus* rootCursus;
        bool readFile(const QString& fileName);

    private:
        void readDossier();
        void readRecursiveCursus(Cursus_Etudiant*ce);
        Inscription& readInscription(Inscription &in);
        Semestre& readSemestre(Semestre& sem);
        UV* readUv();
        Equivalence& readEquivalence(Equivalence& equi);
        Credits& readCredits(Credits& cred);
        QList<Inscription> readSolution();
        Inscription& readPrevision(Inscription& prev);
        void skipUnknownElement();

        Dossier* dossierAremplir;
        QXmlStreamReader reader;
    };
}

#endif