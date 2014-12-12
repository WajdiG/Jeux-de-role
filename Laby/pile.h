typedef struct {int x, y;}t_coordonees;

void initpile(void);
void empiler(t_coordonees coord);
void depiler(t_coordonees *coord);
int pilevide(void);
int sommet_pile(t_coordonees *coord);
