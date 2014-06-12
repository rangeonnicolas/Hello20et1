#ifndef DOSSIER_H
#define DOSSIER_H

#include "UV.h"

#include <QString>
#include <QDialog>
#include <QtGui>
#include <QtXml>
#include <QWidget>
#include <QMessageBox>




using namespace UV_credits_types;
namespace question3 {

    enum Note {A, B, C, D, E, FX, F, RES, ABS, EC};
    Note StringToNote (const QString s);

    enum Saison { Automne, Printemps };
    //inline ostream& operator<<(ostream& f, const Saison& s) { if (s==Automne) f<<"A"; else f<<"P"; return f;}
    Saison StringToSaison(const QString s);

    //Categorie devient CreditType
        /*
    enum Categorie {CS, TM, TSH, SP};
    Categorie StringToCategorie(const QString& s);
    QString CategorieToString(Categorie c);
    //ostream& operator<<(ostream& f, const Categorie& s);
    //istream& operator>>(istream& f, Categorie& cat);
    */


    class Semestre {
        Saison saison;
        unsigned int annee;
    public:
        Semestre(Saison s, unsigned int a):saison(s),annee(a){ /*if (annee<1972||annee>2099) throw exception("annee non valide");*/ }
        Semestre(){}
        Saison getSaison() const { return saison; }
        unsigned int getAnnee() const { return annee; }
        void setSaison(const Saison& s){saison=s;}
        void setAnnee(const unsigned int& a){annee=a;}
    };

    //inline ostream& operator<<(ostream& f, const Semestre& s) { return f<<s.getSaison()<<s.getAnnee()%100; }

    class Inscription{
            Semestre semestre;
            Note resultat;
            const UV* uv;
        public:
            Inscription (const UV& u, const Semestre& s, Note res=EC):uv(&u), semestre(s), resultat(res){}
            Inscription (){}
            Inscription (UV* uv, Note res):uv(uv),resultat(res){}
            const UV& getUV()const {return *uv;}
            Semestre getSemestre() const{return semestre;}
            Note getResultat() const {return resultat;}
            void setResultat(const Note& newres){resultat=newres;}
            void setSemestre (const Semestre& s){semestre=s;}
            void setUv(const UV* u){uv=u;}
        };

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
        Cursus(const char* title):CompletionPercentage(title){}
        //Cursus(const Cursus& c):CompletionPercentage(C.title),PROlist(C.PROlist),SOUS_cursus(c.SOUS_cursus);//TODO NICO: ici constructeur de recopie
        Cursus():CompletionPercentage(""){}
        bool is_completed(QList<Inscription> *ti) const;
        inline void addProfil(Profil *p){ PROlist.append(p) ;}
        inline void addSousCursus(Cursus *c){SOUS_cursus.append(c);}
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







    class Equivalence{
        Credits credits;
        Portee cursus_applicable;
    public:
        Credits getCredits();
        Portee getPortee();
        void setCredits(const Credits& c){credits=c;}
        void setPortee(const Portee& p){cursus_applicable=p;}
    };

    class Prevision{//refaire en utilisant le design pattern adapter
        Semestre semestre;
        const UV* uv;
    public:
        Prevision(Semestre s, const UV* u):semestre(s), uv(u){}
        Prevision(){}
        Semestre getSemestre()const{return semestre;}
        const UV getUV()const; //pas inline car il faut appeller getTitre(), getCode ... de UV
        void setSemestre(const Semestre& s){semestre=s;}
        void setUv(const UV* u){uv=u;}
    };


    class Dossier: public QWidget{
        QString login_etudiant;
        Cursus_Etudiant* cursus;
        QList<Inscription> inscr;
        QList<Equivalence> equivalences;
        QMap<unsigned int,QList<Prevision> > mapSolutions;
        bool modification;
        QString file;
        Dossier();
        ~Dossier();
        static Dossier* instance;

    public:
        void setFile(QString f){file=f;}
        void setLogin_etudiant(QString& l){login_etudiant=l;}
        void setCursus(Cursus_Etudiant* cur){cursus=cur;}
        void setInscr(QList<Inscription>& i){inscr.append(i);}
        void setEqui(QList<Equivalence>& e){equivalences.append(e);}
        void setInscr(Inscription& i){inscr.push_back(i);}
        void setEqui(Equivalence& e){equivalences.push_back(e);}
        void setMapSolutions(unsigned int& i, QList<Prevision>& lP){mapSolutions.insert(i,lP);}
        void load(const QString path, Dossier *doss);
        void save();
        void add_cursus();
        void delete_cursus();
        void add_equivalence();
        void delete_equivalence();
        void ajouter_inscription(Saison sais,unsigned int annee, Note res, QString code);
        void add_inscription(Inscription inscrip);
        void delete_inscription();
        void add_semestre_etranger();
        void delete_semestre_etranger();
        void save_solution();
        static Dossier& getInstance();
        static void libererInstance();

    };

    //class pour lire et récupérer un fichier XML avec le dossier
    class XmlStreamReader
    {
    public:
        XmlStreamReader(Dossier* doss);

        bool readFile(const QString& fileName);

    private:
        void readDossier();
        void readRecursiveCursus(Cursus_Etudiant*ce);
        Inscription& readInscription(Inscription &in);
        Semestre& readSemestre(Semestre& sem);
        UV* readUv();
        Equivalence& readEquivalence(Equivalence& equi);
        Credits& readCredits(Credits& cred);
        QList<Prevision> readSolution();
        Prevision& readPrevision(Prevision& prev);
        void skipUnknownElement();

        Dossier* dossierAremplir;
        QXmlStreamReader reader;
    };



}//fin namespace question3



#endif // DOSSIER_H
