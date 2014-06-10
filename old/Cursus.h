#ifndef CURSUS_H
#define CURSUS_H

#include "temp_FAUSSES-CLASSES.h" //TODO NICO: supprimer cette ligne à la fin

#include <QStandardItem>


namespace CURSUS{

    using namespace question3;
    using namespace UV_credits_types;;

    class CompletionPercentage{
    protected:
        const char* name;//TODO NICO: pertinence de mettre ca la?
    public:
        CompletionPercentage(const char* title):name(title){};
        inline const char* getName() const{return name;};
        inline bool is_completed(QList<Inscription> *ti) const {return (this->completion_percentage(ti) >= 100) ;};
        virtual float completion_percentage(QList<Inscription> *ti) const=0;
    };

    class ValidationRule: public CompletionPercentage{
    public:
        ValidationRule(const char* title): CompletionPercentage(title){  };
        inline bool is_completed(QList<Inscription> *ti) const { return CompletionPercentage::is_completed(ti); };//TODO NICO: voir si on est obligé de redefinir la fonction
        //bool is_completed(QList<Inscription> *ti) const;
        //inline bool is_completed(QList<Inscription> *ti) const {return (this->completion_percentage(ti) >= 100) ;};
        //virtual bool is_completed(QList<Inscription> *ti) const=0;
        virtual float completion_percentage(QList<Inscription> *ti) const=0;
        virtual string toString() const=0;
        virtual void copyIntoQtRuleView(QStandardItem * item) const=0;
    };

    class XUVParmi: public ValidationRule { //TODO NICO:verifier l'héritage publique
        unsigned int nb;
        QList<UV*> UVlist;
    public:
        //bool is_completed(QList<Inscription> *ti) const;
        XUVParmi(unsigned int x, QList<UV*> list,const char* title):ValidationRule(title),nb(x){UVlist = QList<UV*>(list);};
        float completion_percentage(QList<Inscription> *ti) const;
        string toString() const;
        void copyIntoQtRuleView(QStandardItem * item) const;
    };

    class XCreditsParmi: public ValidationRule { //TODO NICO:verifier l'héritage publique
        unsigned int nb;
        QList<const CreditType*> typeList;
        QList<const Portee*> porteeList;
    public:
        //bool is_completed(QList<Inscription> *ti) const;
        XCreditsParmi(unsigned int x, QList<const CreditType*> typeList ,QList<const Portee*> portees,const char* title):ValidationRule(title),nb(x){typeList = QList<const CreditType*>(typeList); porteeList =QList<const Portee*>(portees);};
        float completion_percentage(QList<Inscription> *ti) const;
        string toString() const;
        void copyIntoQtRuleView(QStandardItem * item) const;
    };

    class FonctionOU: public ValidationRule { //TODO NICO:verifier l'héritage publique
        QList <ValidationRule*> VRlist; //TODO important : VRlist normalement ne doit pas etre un tableau de pointeurs pointeur
    public:
        //bool is_completed(QList<Inscription> *ti) const;
        FonctionOU(const char* title):ValidationRule(title){};
        float completion_percentage (QList<Inscription> *ti) const;
        string toString() const;
        inline void addRule(ValidationRule* r){ VRlist.append(r) ;}; //TODO important : r normalement ne doit pas etre un pointeur
        void copyIntoQtRuleView(QStandardItem * item) const;
    };

    class FonctionET: public ValidationRule { //TODO NICO:verifier l'héritage publique
        QList <ValidationRule*> VRlist; //TODO important : VRlist normalement ne doit pas etre un tableau de pointeurs pointeur
    public:
        //bool is_completed(QList<Inscription> *ti) const;
        FonctionET(const char* title):ValidationRule(title){};
        float completion_percentage (QList<Inscription> *ti) const;
        string toString() const;
        inline void addRule(ValidationRule* r){ VRlist.append(r) ;}; //TODO important : r normalement ne doit pas etre un pointeur
        void copyIntoQtRuleView(QStandardItem * item) const;
    };

    class Profil: public CompletionPercentage{
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
        void copyIntoQtRuleView(QStandardItemModel *modeleRegl) const;
    };

    class Cursus: public CompletionPercentage{
    protected:
        QList<Profil*> PROlist;
        QList<Cursus*> SOUS_cursus; 
        //TODO nico: iterator pour les friend class?
    //friend class CUSSUSSelector;
   // friend class CURSUSEditor;
    public:
        Cursus(const char* title):CompletionPercentage(title){};
        //Cursus(const Cursus& c):CompletionPercentage(C.title),PROlist(C.PROlist),SOUS_cursus(c.SOUS_cursus);//TODO NICO: ici constructeur de recopie
        bool is_completed(QList<Inscription> *ti) const;
        inline void addProfil(Profil *p){ PROlist.append(p) ;};
        inline void addSousCursus(Cursus *c){SOUS_cursus.append(c);};
        float completion_percentage (QList<Inscription> *ti) const;
        string toString() const;         
        //TODO NICO: ne pas oublier la suppression
        //TODO NICO: ici il y a surement de la factory derriere.
        //TODO NICO: verifier toutes les associations........
        //TODO NICO : DP composite
        //TODO NICO : DP decorator?:
    //private:
        const QList<Profil*> getProfileList() const;
        const QList<Cursus*> getSOUSCursusList() const;
        void copyIntoQtCursusView(QStandardItem *itemCursus) const;
        void copyIntoQtProfilView(QStandardItemModel *modeleProfil,int begin) const;
        Cursus* cloneRootElement() const;

   };

    class Cursus_Etudiant: public Cursus{
         Cursus* CursusDeReference;
     public:
         Cursus_Etudiant(Cursus* ref):Cursus((const Cursus&)(*(ref->cloneRootElement()))),CursusDeReference(ref){};
         inline void setCursusReference(Cursus* ref){this->CursusDeReference=ref;};
         inline Cursus* getCursusReference(){return CursusDeReference;};
    };

   class QStandardItem_Cursus: public QStandardItem{//TODO NICO si ca fonctionne, en parler ds le rapport
        Cursus* cursus;
    public:
        QStandardItem_Cursus(const char* name,Cursus *c):QStandardItem::QStandardItem(name),cursus(c){};
        inline Cursus* getCursus()const {return cursus;};
   };

   class QStandardItem_Cursus_Etudiant: public QStandardItem{//TODO NICO si ca fonctionne, en parler ds le rapport
        Cursus_Etudiant* cursus;
    public:
        QStandardItem_Cursus_Etudiant(const char* name,Cursus_Etudiant *c):QStandardItem::QStandardItem(name),cursus(c){};
        inline Cursus_Etudiant* getCursus()const {return cursus;};
   };

   class QStandardItem_Profil: public QStandardItem{//TODO NICO si ca fonctionne, en parler ds le rapport
        Profil* profil;
    public:
        QStandardItem_Profil(const char* name,Profil *c):QStandardItem::QStandardItem(name),profil(c){};
        inline Profil* getProfil()const {return profil;};
   };


}

#endif // CURSUS_H






























/*




#ifndef CURSUS_H
#define CURSUS_H

#include "temp_FAUSSES-CLASSES.h" //TODO NICO: supprimer cette ligne à la fin

#include <QStandardItem>


namespace CURSUS{

    using namespace FOOO;
    using namespace UV_credits_types;;

    class CompletionPercentage{
    protected:
        const char* name;//TODO NICO: pertinence de mettre ca la?
    public:
        CompletionPercentage(const char* title):name(title){};
        inline const char* getName() const{return name;};
        inline bool is_completed(QList<FOOO::Inscription> *ti) const {return (this->completion_percentage(ti) >= 100) ;};
        virtual float completion_percentage(QList<FOOO::Inscription> *ti) const=0;
    };

    class ValidationRule: public CompletionPercentage{
    public:
        ValidationRule(const char* title): CompletionPercentage(title){  };
        inline bool is_completed(QList<FOOO::Inscription> *ti) const { return CompletionPercentage::is_completed(ti); };//TODO NICO: voir si on est obligé de redefinir la fonction
        //bool is_completed(QList<Inscription> *ti) const;
        //inline bool is_completed(QList<Inscription> *ti) const {return (this->completion_percentage(ti) >= 100) ;};
        //virtual bool is_completed(QList<Inscription> *ti) const=0;
        virtual float completion_percentage(QList<FOOO::Inscription> *ti) const=0;
        virtual string toString() const=0;
        virtual void copyIntoQtRuleView(QStandardItem * item) const=0;
    };

    class XUVParmi: public ValidationRule { //TODO NICO:verifier l'héritage publique
        unsigned int nb;
        QList<UV*> UVlist;
    public:
        //bool is_completed(QList<Inscription> *ti) const;
        XUVParmi(unsigned int x, QList<UV*> list,const char* title):ValidationRule(title),nb(x),UVlist(list){};
        float completion_percentage(QList<Inscription> *ti) const;
        string toString() const;
        void copyIntoQtRuleView(QStandardItem * item) const;
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
        void copyIntoQtRuleView(QStandardItem * item) const;
    };

    class FonctionOU: public ValidationRule { //TODO NICO:verifier l'héritage publique
        QList <ValidationRule*> VRlist; //TODO important : VRlist normalement ne doit pas etre un tableau de pointeurs pointeur
    public:
        //bool is_completed(QList<Inscription> *ti) const;
        FonctionOU(const char* title):ValidationRule(title){};
        float completion_percentage (QList<Inscription> *ti) const;
        string toString() const;
        inline void addRule(ValidationRule* r){ VRlist.append(r) ;}; //TODO important : r normalement ne doit pas etre un pointeur
        void copyIntoQtRuleView(QStandardItem * item) const;
    };

    class FonctionET: public ValidationRule { //TODO NICO:verifier l'héritage publique
        QList <ValidationRule*> VRlist; //TODO important : VRlist normalement ne doit pas etre un tableau de pointeurs pointeur
    public:
        //bool is_completed(QList<Inscription> *ti) const;
        FonctionET(const char* title):ValidationRule(title){};
        float completion_percentage (QList<Inscription> *ti) const;
        string toString() const;
        inline void addRule(ValidationRule* r){ VRlist.append(r) ;}; //TODO important : r normalement ne doit pas etre un pointeur
        void copyIntoQtRuleView(QStandardItem * item) const;
    };

    class Profil: public CompletionPercentage{
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
        void copyIntoQtRuleView(QStandardItemModel *modeleRegl) const;
    };

    class Cursus: public CompletionPercentage{
    protected:
        QList<Profil*> PROlist;
        QList<Cursus*> SOUS_cursus; 
        //TODO nico: iterator pour les friend class?
    //friend class CUSSUSSelector;
   // friend class CURSUSEditor;
    public:
        Cursus(const char* title):CompletionPercentage(title){};
        //Cursus(const Cursus& c):CompletionPercentage(C.title),PROlist(C.PROlist),SOUS_cursus(c.SOUS_cursus);//TODO NICO: ici constructeur de recopie
        bool is_completed(QList<Inscription> *ti) const;
        inline void addProfil(Profil *p){ PROlist.append(p) ;};
        inline void addSousCursus(Cursus *c){SOUS_cursus.append(c);};
        float completion_percentage (QList<Inscription> *ti) const;
        string toString() const;         
        //TODO NICO: ne pas oublier la suppression
        //TODO NICO: ici il y a surement de la factory derriere.
        //TODO NICO: verifier toutes les associations........
        //TODO NICO : DP composite
        //TODO NICO : DP decorator?:
    //private:
        const QList<Profil*> getProfileList() const;
        const QList<Cursus*> getSOUSCursusList() const;
        void copyIntoQtCursusView(QStandardItem *itemCursus) const;
        void copyIntoQtProfilView(QStandardItemModel *modeleProfil,int begin) const;
        Cursus* cloneRootElement() const;

   };

    class Cursus_Etudiant: public Cursus{
         Cursus* CursusDeReference;
     public:
         Cursus_Etudiant(Cursus* ref):Cursus((const Cursus&)(*(ref->cloneRootElement()))),CursusDeReference(ref){};
         inline void setCursusReference(Cursus* ref){this->CursusDeReference=ref;};
         inline Cursus* getCursusReference(){return CursusDeReference;};
    };

   class QStandardItem_Cursus: public QStandardItem{//TODO NICO si ca fonctionne, en parler ds le rapport
        Cursus* cursus;
    public:
        QStandardItem_Cursus(const char* name,Cursus *c):QStandardItem::QStandardItem(name),cursus(c){};
        inline Cursus* getCursus()const {return cursus;};
   };

   class QStandardItem_Cursus_Etudiant: public QStandardItem{//TODO NICO si ca fonctionne, en parler ds le rapport
        Cursus_Etudiant* cursus;
    public:
        QStandardItem_Cursus_Etudiant(const char* name,Cursus_Etudiant *c):QStandardItem::QStandardItem(name),cursus(c){};
        inline Cursus_Etudiant* getCursus()const {return cursus;};
   };

   class QStandardItem_Profil: public QStandardItem{//TODO NICO si ca fonctionne, en parler ds le rapport
        Profil* profil;
    public:
        QStandardItem_Profil(const char* name,Profil *c):QStandardItem::QStandardItem(name),profil(c){};
        inline Profil* getProfil()const {return profil;};
   };


}

#endif // CURSUS_H


*/
