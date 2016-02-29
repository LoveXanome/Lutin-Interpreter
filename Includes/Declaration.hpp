/*************************************************************************
                           Declaration  
*************************************************************************/

#if!defined ( DECLARATION_HPP )
#define DECLARATION_HPP

#include <string>


class Declaration
{

public:
//----------------------------------------------------- Méthodes publiques


//-------------------------------------------- Constructeurs - destructeur
    Declaration();
    virtual ~Declaration();


protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	string identifiant;
};

//--------------------------- Autres définitions dépendantes de <Declaration>

#endif // DECLARATION_HPP

