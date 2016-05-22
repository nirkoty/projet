#include "litteralecomplexe.h"
#include "litteralerationnelle.h"
#include "litteralereelle.h"
#include "litteraleentiere.h"

LitteraleComplexe::LitteraleComplexe(bool neg, Litterale re, Litterale im) : Litterale(neg), partieRelle(im), partieImaginaire(im)
{

}


bool LitteraleComplexe::estLitteraleComplexe(QString bloc){
    if(bloc.indexOf('$')==-1)
        return false;

    QString strRe =  bloc.section('$', 0, 0);
    QString strIm =  bloc.section('$', 1, 1);

    bool ok = true;
    if(!LitteraleEntiere::estLitteraleEntiere(strRe) && !LitteraleReelle::estLitteraleReelle(strRe) && !LitteraleRationnelle::estLitteraleRationnelle(strRe))
        return false;
    if(!LitteraleEntiere::estLitteraleEntiere(strIm) && !LitteraleReelle::estLitteraleReelle(strIm) && !LitteraleRationnelle::estLitteraleRationnelle(strIm))
        return false;

    return true;
}