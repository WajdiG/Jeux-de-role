
#ifndef __JDR1_0_H__
#define __JDR1_0_H__

#include "crea_avatar.h"
#include "sauvegarde.h"
#include "charger.h"
#include "pile_tab.h"
#include "region.h"
#include "monde.h"


/**
*\struct t_statcombat
*\brief structure contenant toutes les statistiques liées au combat
*/
typedef struct{int victoire,defaite,total; float pourvic,pourdef;}t_statcombat;

void afficher_joueur();
void nouvelle_partie();
void charger_par();

#endif