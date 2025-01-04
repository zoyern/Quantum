#THIS IS NOTE CHECK DOCS FOR IMAGES AND EXEMPLES

```bash

theta et phi 0 ,0 intensité == 100% -> 0
theta et phi 0 ,0 == 100% -> 0
1 Q bit = (1,0)  (100% de te donné 0 et 0% de te donné 1)
superposition = change les probabilité to P(0)=∣0.707107∣2=0.5(50%) - P(1)=∣0.707107∣2=0.5(50%)  (50%,50%)
									d'etre 
porte X (NOT) inverse les valeur = (30%, 70%) -> (70%, 30%) 

-------------------------------------------------------------
Fonction : Crée un état quantique (ket) avec probabilité et φ Energy
-------------------------------------------------------------

φ Energy représente l état de phase :
-  1.0 → Constructif (alignement parfait).
-  0.0 → Neutre (aucun effet, équilibre).
- -1.0 → Destructif (opposition parfaite).
Cas supplémentaires :
-  0 * -1 = 0 → Neutre car aucun effet malgré la phase destructrice.
-  1 * 0 = 0 → Neutre car l un est neutre et n ajoute rien à la phase.
- -1 * 0 = 0 → Neutre même avec opposition (l état neutre domine).
-  0 * 0 = 0 → Neutre car aucun effet sur la phase.
- -1 * -1 = 1 → Constructif car alignement inversé qui se ré-aligne.
- -1 * 1 = -1 → Destructif car opposition directe des phases.

Détail des concepts :
1. Constructif (Alignement)

    Quand deux phases sont en phase (φ1=φ2φ1​=φ2​), elles renforcent l’amplitude et augmentent la probabilité d’observer un résultat spécifique.
    Exemple :
    φ1=1φ1​=1 et φ2=1φ2​=1 → Constructif : Résultat = 1.0

2. Destructif (Opposition)

    Lorsque deux phases sont opposées (φ1=−φ2φ1​=−φ2​), elles peuvent s’annuler en réduisant l’amplitude globale, ce qui entraîne une faible probabilité ou une annulation totale.
    Exemple :
    φ1=1φ1​=1 et φ2=−1φ2​=−1 → Destructif : Résultat = -1.0

3. Neutre (Pas d’effet)

    Une phase neutre (φ=0φ=0) n’ajoute ni n’enlève d’intensité. Elle agit comme un passe-partout et ne modifie pas la dynamique des phases.
    Exemple :
    φ1=0φ1​=0 et φ2=−1φ2​=−1 → Neutre : Résultat = 0.0

4. Semi-constructif/destructif (Partiels)

    Lorsque deux phases sont partiellement alignées ou désalignées, elles produisent un effet intermédiaire.
    Exemple :
    φ1=0.5φ1​=0.5 et φ2=−0.5φ2​=−0.5 → Semi-destructif : Résultat = -0.25

Exemples d’application pratique
Couleurs et lumière :

    Constructif (1 * 1) → Mélange de couleurs brillantes et saturation élevée.
    Destructif (-1 * 1) → Annulation des couleurs, produisant une ombre ou transparence.
    Neutre (0 * 1) → Couleur inchangée ou transfert direct.

Réflexions et transparence :

    Constructif (réflexion parfaite) → Miroirs brillants.
    Destructif (absorption) → Opaque ou matériaux absorbants.
    Neutre (transparence) → Passage à travers un objet sans perte.

Interférences en réseau :

    Alignement parfait (1 * 1) → Pic d’interférence lumineuse.
    Annulation parfaite (-1 * -1) → Trous sombres dans le schéma d’interférence.

-------------------------------------------------------------
photon
-------------------------------------------------------------
Type d’interaction			|	Effet physique simulé
-------------------------------------------------------------
Transmission (Transparence)	|	Continue avec amplitude réduite.
Réflexion (Miroir)			|	Changement de direction avec phase décalée.
Absorption (Ombre)			|	Amplitude = 0 (pixel noir ou absorbé).
Diffusion (Verre dépoli)		|	Modifie la phase et répartit l’intensité.
Réfraction (Eau, lentille)	|	Change direction et vitesse (effet lentille).
-------------------------------------------------------------
```
