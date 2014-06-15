#ifndef DOSSIER_H
#define DOSSIER_H

#include "UV.h"
#include "inscription.h"

#include <QString>
#include <QDialog>
#include <QtGui>
#include <QtXml>
#include <QWidget>
#include <QMessageBox>

using namespace UV_credits_types;

namespace INSCRIPTIONS {

    class CompletionPercentage{
    protected:
        const char* name;
    public:
        CompletionPercentage(const char* title):name(title){};
        inline const char* getName() const{return name;};
        inline bool is_completed(QList<Inscription> *ti) const {return (this->completion_percentage(ti) >= 100) ;};
        virtual float completion_percentage(QList<Inscription> *ti) const=0;
        virtual void testNullPtr(bool recursiv,bool debug)const=0;
    };

    class ValidationRule: public CompletionPercentage{
    public:
        ValidationRule(const char* title): CompletionPercentage(title){  };
        inline bool is_completed(QList<Inscription> *ti) const { return CompletionPercentage::is_completed(ti); };
        virtual float completion_percentage(QList<Inscription> *ti) const=0;
        virtual string toString() const=0;
        virtual void copyIntoQtRuleView(QStandardItem * item) const=0;
    };

    class XUVParmi: public ValidationRule { 
        unsigned int nb;
        QList<UV*> UVlist;
        string nb_str;
    public:
        //bool is_completed(QList<Inscription> *ti) const;
        XUVParmi(unsigned int x, const QList<UV*>& list,const char* title,string nb_str):ValidationRule(title),nb(x),UVlist(list),nb_str(nb_str){};
        float completion_percentage(QList<Inscription> *ti) const;
        string toString() const;
        void copyIntoQtRuleView(QStandardItem * item) const;
        void testNullPtr(bool recursiv,bool debug)const;
    };

    class XCreditsParmi: public ValidationRule { 
        unsigned int nb;
        QList<const CreditType*> typeList;
        QList<const Portee*> porteeList;
        string nb_str;
    public:
        //bool is_completed(QList<Inscription> *ti) const;
        XCreditsParmi(unsigned int x, const QList<const CreditType*>& typeList ,const QList<const Portee*>& portees,const char* title,string nb_str):ValidationRule(title),nb(x),typeList(typeList),porteeList(portees),nb_str(nb_str){};
        float completion_percentage(QList<Inscription> *ti) const;
        string toString() const;
        void copyIntoQtRuleView(QStandardItem * item) const;
        void testNullPtr(bool recursiv,bool debug)const;
    };

    class FonctionOU: public ValidationRule { 
        QList <ValidationRule*> VRlist; 
    public:
        //bool is_completed(QList<Inscription> *ti) const;
        FonctionOU(const char* title):ValidationRule(title),VRlist(){};
        float completion_percentage (QList<Inscription> *ti) const;
        string toString() const;
        inline void addRule(ValidationRule* r){ VRlist.append(r) ;};
        void copyIntoQtRuleView(QStandardItem * item) const;
        void testNullPtr(bool recursiv,bool debug)const;
    };

    class FonctionET: public ValidationRule {
        QList <ValidationRule*> VRlist;
    public:
        FonctionET(const char* title):ValidationRule(title),VRlist(){};
        float completion_percentage (QList<Inscription> *ti) const;
        string toString() const;
        inline void addRule(ValidationRule* r){ VRlist.append(r) ;}; 
        void copyIntoQtRuleView(QStandardItem * item) const;
        void testNullPtr(bool recursiv,bool debug)const;
    };

    class Profil: public CompletionPercentage{
        QList<ValidationRule*> VRlist;
    public:
        Profil(const char* title):CompletionPercentage(title){};
        bool is_completed(QList<Inscription> *ti) const;
        inline void addValidationRule(ValidationRule *r){ VRlist.append(r) ;};
        float completion_percentage (QList<Inscription> *ti) const;
        string toString(int k) const;
        void copyIntoQtRuleView(QStandardItemModel *modeleRegl) const;
        void testNullPtr(bool recursiv,bool debug)const;
    };

    class Cursus: public CompletionPercentage{
    protected:
        QList<Profil*> PROlist;
        QList<Cursus*> SOUS_cursus;
    public:
        Cursus(const char* title):CompletionPercentage(title){}
        Cursus():CompletionPercentage(""){}
        bool is_completed(QList<Inscription> *ti) const;
        inline void addProfil(Profil *p){ PROlist.append(p) ;}
        inline void addSousCursus(Cursus *c){SOUS_cursus.append(c);}
        float completion_percentage (QList<Inscription> *ti) const;
        string toString(int k) const;
        const QList<Profil*> getProfileList() const;
        const QList<Cursus*> getSOUSCursusList() const;
        void copyIntoQtCursusView(QStandardItem *itemCursus) const;
        void copyIntoQtProfilView(QStandardItemModel *modeleProfil,int begin) const;
        Cursus* cloneRootElement() const;
        void testNullPtr(bool recursiv,bool debug)const;
   };

    class Cursus_Etudiant: public Cursus{
         Cursus* CursusDeReference;
     public:
         Cursus_Etudiant(Cursus* ref):Cursus((const Cursus&)(*(ref->cloneRootElement()))),CursusDeReference(ref){};
         inline void setCursusReference(Cursus* ref){this->CursusDeReference=ref;};
         inline Cursus* getCursusReference(){return CursusDeReference;};
        void testNullPtr(bool recursiv,bool debug)const;
    };

   class QStandardItem_Cursus: public QStandardItem{
        Cursus* cursus;
    public:
        QStandardItem_Cursus(const char* name,Cursus *c):QStandardItem::QStandardItem(name),cursus(c){};
        inline Cursus* getCursus()const {return cursus;};
   };

   class QStandardItem_Cursus_Etudiant: public QStandardItem{
        Cursus_Etudiant* cursus;
    public:
        QStandardItem_Cursus_Etudiant(const char* name,Cursus_Etudiant *c):QStandardItem::QStandardItem(name),cursus(c){};
        inline Cursus_Etudiant* getCursus()const {return cursus;};
   };

   class QStandardItem_Profil: public QStandardItem{
        Profil* profil;
    public:
        QStandardItem_Profil(const char* name,Profil *c):QStandardItem::QStandardItem(name),profil(c){};
        inline Profil* getProfil()const {return profil;};
   };




    class Equivalence{
        Credits credits;
        Portee cursus_applicable;
    public:
        Credits getCredits();
        Portee getPortee();
        void setCredits(const Credits& c){credits=c;}
        void setPortee(const Portee& p){cursus_applicable=p;}
    };


    class Dossier{
        QString login_etudiant;
        Cursus_Etudiant* cursusEtu;
        QList<Inscription> inscr;
        QList<Equivalence> equivalences;
        QMap<unsigned int,QList<Inscription> > mapSolutions;
        bool modification;
        QString file;
        Dossier();
        ~Dossier(){
            delete cursusEtu;
        };
        static Dossier* instance;

    public:
        void setFile(QString f){file=f;}
        void setLogin_etudiant(QString& l){login_etudiant=l;}
        void setCursus(Cursus_Etudiant* cursusEtu){cursusEtu=cursusEtu;}
        void setInscr(QList<Inscription>& i){inscr.append(i);}
        void setEqui(QList<Equivalence>& e){equivalences.append(e);}
        void setInscr(Inscription& i){inscr.push_back(i);}
        QList<Inscription> getInscr()const {return inscr;}
        void setEqui(Equivalence& e){equivalences.push_back(e);}
        void setMapSolutions(unsigned int& i, QList<Inscription>& lP){mapSolutions.insert(i,lP);}
        void load(const QString path, Dossier *doss);
        void save();
        void add_cursus(Cursus_Etudiant* cursusEtu){this->cursusEtu=cursusEtu;}
        void delete_cursus();
        void add_equivalence();
        void delete_equivalence();
       // void ajouter_inscription(Saison sais,unsigned int annee, Note res, QString code);
        void add_inscription(Inscription inscrip);
        void delete_inscription();
        void add_semestre_etranger();
        void delete_semestre_etranger();
        void save_solution();
        Cursus_Etudiant* getCursusEtu()const{return cursusEtu;}
        QMap<unsigned int,QList<Inscription> > getMapSol()const{return mapSolutions;}
        static Dossier& getInstance();
        static void libererInstance();

    };

}

#endif // DOSSIER_H
