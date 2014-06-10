#ifndef CURSUS_H
#define CURSUS_H

#include <QStandardItem>
#include "temp_FAUSSES-CLASSES.h" //TODO NICO : supprimer cette ligne à la fin
using namespace FOOO; //TODO NICO : supprimer cette ligne à la fin
using namespace UV_credits_types;

namespace CURSUS{

    class CompletionPercentage{
    protected:
        const char* name;//TODO NICO: pertinence de mettre ca la?
    public:
        CompletionPercentage(const char* title):name(title){};
        inline const char* getName() const{return name;};
        inline bool is_completed(QList<Inscription> *ti) const {return (this->completion_percentage(ti) >= 100) ;};
        virtual float completion_percentage(QList<Inscription> *ti) const=0;
    };

    class ValidationRule: private CompletionPercentage{
    public:
        ValidationRule(const char* title): CompletionPercentage(title){  };
        inline bool is_completed(QList<Inscription> *ti) const { return CompletionPercentage::is_completed(ti); };//TODO NICO: voir si on est obligé de redefinir la fonction
        //bool is_completed(QList<Inscription> *ti) const;
        //inline bool is_completed(QList<Inscription> *ti) const {return (this->completion_percentage(ti) >= 100) ;};
        //virtual bool is_completed(QList<Inscription> *ti) const=0;
        virtual float completion_percentage(QList<Inscription> *ti) const=0;
        virtual string toString() const=0;
    };

    class XUVParmi: public ValidationRule { //TODO NICO:verifier l'héritage publique
        unsigned int nb;
        QList<UV*> UVlist;
    public:
        //bool is_completed(QList<Inscription> *ti) const;
        XUVParmi(unsigned int x, QList<UV*> list,const char* title):ValidationRule(title),nb(x),UVlist(list){};
        float completion_percentage(QList<Inscription> *ti) const;
        string toString() const;
    };

    class XCreditsParmi: public ValidationRule { //TODO NICO:verifier l'héritage publique
        unsigned int nb;
        QList<const CreditType*> typeList;
        QList<const Portee*> porteeList;
    public:
        //bool is_completed(QList<Inscription> *ti) const;
        XCreditsParmi(unsigned int x, QList<const CreditType*> typeList ,QList<const Portee*> portees,const char* title):ValidationRule(title),nb(x),typeList(typeList),porteeList(portees){};
        float completion_percentage(QList<Inscription> *ti) const;
        string toString() const;
    };

    class FonctionOU: public ValidationRule { //TODO NICO:verifier l'héritage publique
        QList <ValidationRule*> VRlist; //TODO important : VRlist normalement ne doit pas etre un tableau de pointeurs pointeur
    public:
        //bool is_completed(QList<Inscription> *ti) const;
        FonctionOU(const char* title):ValidationRule(title){};
        float completion_percentage (QList<Inscription> *ti) const;
        string toString() const;
        inline void addRule(ValidationRule* r){ VRlist.append(r) ;}; //TODO important : r normalement ne doit pas etre un pointeur
    };

    class Profil: private CompletionPercentage{
        QList<ValidationRule*> VRlist;
    public:
        Profil(const char* title):CompletionPercentage(title){};
        bool is_completed(QList<Inscription> *ti) const;
        inline void addValidationRule(ValidationRule *r){ VRlist.append(r) ;};
        float completion_percentage (QList<Inscription> *ti) const;
        string toString() const;         
        //TODO NICO: ne pas oublier la suppression
        // TODO NICO: ici il y a surement de la factory derriere.
        //verifier toutes les associations........
    };

    class Cursus: private CompletionPercentage{
        QList<Profil*> PROlist;
        QList<Cursus*> SOUS_cursus; 
    public:
        Cursus(const char* title):CompletionPercentage(title){};
        bool is_completed(QList<Inscription> *ti) const;
        inline void addProfil(Profil *p){ PROlist.append(p) ;};
        inline void addSousCursus(Cursus *c){SOUS_cursus.append(c);};
        float completion_percentage (QList<Inscription> *ti) const;
        string toString() const;         
        //TODO NICO: ne pas oublier la suppression
        // TODO NICO: ici il y a surement de la factory derriere.
        //verifier toutes les associations........
        //TODO: DP composite
    };
}

#endif // CURSUS_H
