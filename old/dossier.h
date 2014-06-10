#ifndef DOSSIER_H
#define DOSSIER_H
#include <QString>
#include "class_q1.h"
#include "UV.h"
#include <QDialog>
#include <QtGui>
#include <QtXml>
#include <QWidget>
#include <QMessageBox>

class UTProfilerException{
public:
    UTProfilerException(const QString& message, const QString &f="na", unsigned int l=0):
        info(message),file(f),line(l){}
    QString getInfo() const { return info; }
#ifndef NDEBUG
    // retourne le fichier dans lequel cettte exception a été levée.
    QString getFile() const { return file; }
    // retourne la ligne du fichier à laquelle cette exception a été levée.
    unsigned int getLine() const { return line; }
#endif
private:
    QString info;
    QString file;
    unsigned int line;

};
using namespace UV_credits_types;
namespace question3 {

    enum Note {A, B, C, D, E, FX, F, RES, ABS, EC};
    Note StringToNote (const QString s);

    enum Categorie {CS, TM, TSH, SP};
    Categorie StringToCategorie(const QString& s);
    QString CategorieToString(Categorie c);
    //ostream& operator<<(ostream& f, const Categorie& s);
    //istream& operator>>(istream& f, Categorie& cat);


    enum Saison { Automne, Printemps };
    //inline ostream& operator<<(ostream& f, const Saison& s) { if (s==Automne) f<<"A"; else f<<"P"; return f;}
    Saison StringToSaison(const QString s);

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
        const UV& getUV()const {return *uv;}
        Semestre getSemestre() const{return semestre;}
        Note getResultat() const {return resultat;}
        void setResultat(const Note& newres){resultat=newres;}
        void setSemestre (const Semestre& s){semestre=s;}
        void setUv(const UV* u){uv=u;}
    };

//    class Cursus{

//    };

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
        QList<Cursus> cursus;
        QList<Inscription> inscr;
        QList<Equivalence> equivalences;
        QMap<unsigned int,QList<Prevision> > mapSolutions;
        bool modification;
        QString file;
        Dossier();
        ~Dossier();
        static Dossier* instance;

    public:
        void setLogin_etudiant(QString& l){login_etudiant=l;}
        void setCursus(Cursus& cur){cursus.push_back(cur);}
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
        XmlStreamReader(QFile* f);

        bool readFile(Dossier* doss);

    private:
        void readDossier(Dossier *doss);
        Cursus& readCursus(Cursus &cur);
        Inscription& readInscription(Inscription &in);
        Semestre& readSemestre(Semestre& sem);
        UV* readUv();
        Equivalence& readEquivalence(Equivalence& equi);
        Credits& readCredits(Credits& cred);
        QList<Prevision> readSolution();
        Prevision& readPrevision(Prevision& prev);
        void skipUnknownElement();

        QFile* file;
        QXmlStreamReader reader;
    };



}//fin namespace question3



#endif // DOSSIER_H
