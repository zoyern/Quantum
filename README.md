#THIS IS NOTE CHECK DOCS FOR IMAGES AND EXEMPLES

```bash
0  90 180 270 360(0)
-1 -0.5 0 0.5 1


theta et phi 0 ,0 intensité == 100% -> 0
theta et phi 0 ,0 == 100% -> 0

theta 180 permet a phi de se déplacé de 360° mais n'aura pas d'energie
c est a dire que la rotation a bien lieu mais mais la probabilité n evolue plu soit 0 soit 1 donc tout le resultat se base sur phi et notre position de départ theta 
defini a 0 pour 0 energie et 

1 Q bit = (1,0)  (100% de te donné 0 et 0% de te donné 1)
superposition = change les probabilité to
P(0)=∣0.707107∣2=0.5(50%) - P(1)=∣0.707107∣2=0.5(50%)  (50%,50%)
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
Diffusion (Verre dépoli)	|	Modifie la phase et répartit l’intensité.
Réfraction (Eau, lentille)	|	Change direction et vitesse (effet lentille).
-------------------------------------------------------------
```

```bash
Qubit et Superposition
1. Définitions Initiales :

Un qubit est représenté comme une combinaison pondérée des états |0⟩ et |1⟩ :
∣ψ⟩=a∣0⟩+b∣1⟩
∣ψ⟩=a∣0⟩+b∣1⟩

où :

    a et b sont les amplitudes complexes associées aux états.
    |a|² et |b|² représentent les probabilités respectives d’observer 0 ou 1.
    Amplitude = √(Probabilité) détermine l’intensité.

2. Rotation θ et Phase φ :

θ (theta) et φ (phi) sont les coordonnées sphériques sur la sphère de Bloch :

    θ contrôle l’amplitude (probabilités entre |0⟩ et |1⟩).
        0° → Pur |0⟩
        90° → Superposition équilibrée (50%-50%)
        180° → Pur |1⟩
    φ contrôle la phase (interférences et rotations autour de l’axe Z).
        0° → Phase neutre (constructif)
        180° → Phase opposée (destructif)
        360° → Retour au point initial (périodicité)

Échelles Normalisées

    θ ∈ [-2, 2] :
        -2 → 180° (État opposé pur)
        2 → 0° (État pur aligné)
    φ ∈ [-2, 2] :
        -2 → -180° (Phase inversée)
        2 → 180° (Rotation complète)

Portes et Transformations de Base
Porte	Effet	Exemple
X (NOT)	Inverse les états (	0⟩ ↔
H (Hadamard)	Crée une superposition équilibrée (50%-50%).	P(0) = 50%, P(1) = 50%.
Z (Phase)	Ajoute un déphasage de 180° sans changer les probabilités.	φ passe de 0° à 180°.
RX(θ)	Rotation autour de X en angle θ.	Change θ entre -2 et 2.
RZ(φ)	Rotation autour de Z en angle φ.	Change φ entre -2 et 2.
Combinaisons et Interférences
-------------------------------------------------------------
1. Types d’Énergies de Phase φ :
-------------------------------------------------------------
φ Energy	Type d’Interférence	Effet Physique
-------------------------------------------------------------
1.0	Constructif	Phases alignées → Amplitude maximale.
-------------------------------------------------------------
0.0	Neutre	Pas de modification → Aucune influence sur la phase.
-------------------------------------------------------------
-1.0	Destructif	Phases opposées → Annulation partielle ou totale.
-------------------------------------------------------------
2. Cas Spécifiques
-------------------------------------------------------------
Combinaison	Résultat Interprété
-------------------------------------------------------------
1 * 1 = 1	Constructif (alignement).
-------------------------------------------------------------
-1 * -1 = 1	Constructif (réalignement).
-------------------------------------------------------------
1 * -1 = -1	Destructif (opposition).
-------------------------------------------------------------
0 * 0 = 0	Neutre (aucun effet).
-------------------------------------------------------------
0 * -1 = 0	Neutre même avec opposition.
-------------------------------------------------------------
0.5 * -0.5 = -0.25	Semi-destructif (partiel).
-------------------------------------------------------------
Effets Physiques Simulés avec Photons
-------------------------------------------------------------
Type d’interaction	Effet physique simulé	Exemple en utilisant θ et φ
-------------------------------------------------------------
Transmission (Transparence)	Continue avec amplitude réduite, conservant la phase.	θ -------------------------------------------------------------proche de 90°, φ ≈ 0° (Constructif).
Réflexion (Miroir)	Changement de direction avec un décalage de phase φ.	φ décalé de 180° (Destructif).
Absorption (Ombre)	Amplitude réduite à 0 (pixel noir ou absorbé).	θ = 180°, φ indéfini, probabilité = 0%.
Diffusion (Verre dépoli)	Modifie la phase et répartit l’intensité aléatoirement.	φ variable entre 0° et 360°, probabilité dispersée.
Réfraction (Eau, lentille)	Change la direction et la vitesse (effet lentille).	θ réduit (focalisation) et φ modifié.
Exemple Numérique
-------------------------------------------------------------
États Initiaux :
-------------------------------------------------------------
État	Probabilité (%)	Amplitude	θ (°)	φ (°)	Énergie θ [-2, 2]	Énergie φ [-2, 2]
0	30.00	0.55	110.00	0.00	-0.6	0.0
-------------------------------------------------------------
1	70.00	0.84	70.00	180.00	0.6		1.0
-------------------------------------------------------------
Combinaisons et Résultats :
-------------------------------------------------------------
Combinaison (φ Energy)	Amplitude	θ (°)	φ (°)	Probabilité (%)
1.0 × 1.0	1.00	0.00	0.00	100.00
-------------------------------------------------------------
-1.0 × -1.0	1.00	0.00	180.00	100.00
-------------------------------------------------------------
1.0 × -1.0	0.00	180.00	180.00	0.00
-------------------------------------------------------------
0.0 × 1.0	0.50	90.00	90.00	50.00
-------------------------------------------------------------
```



j'ai un code en cpp avec qpp et qengine :


#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <string>
#include "qpp/qpp.hpp"

using namespace qpp;

// -------------------------------------------------------------
// Classe QuantumColor - Gestion des couleurs et interactions quantiques
// -------------------------------------------------------------
class QuantumColor {
private:
    double probability;  // Probabilité (%)
    double theta;        // θ (amplitude, en degrés)
    double phi;          // φ (phase, en degrés)
    double phi_energy;   // Énergie de phase [-2, 2]
    std::string color_hex; // Couleur HEX
    ket state;           // État quantique

    // Conversion HEX avec couleur fixe donnée
    std::string to_hex(int r, int g, int b) const {
        std::stringstream ss;
        ss << std::hex << std::setw(2) << std::setfill('0') << r
           << std::setw(2) << std::setfill('0') << g
           << std::setw(2) << std::setfill('0') << b;
        return ss.str();
    }

    // Calcul du ket avec un circuit quantique
    ket calculate_ket(double prob, double phi_energy) const {
        double amp1 = sqrt(prob / 100.0);
        double amp0 = sqrt(1.0 - (prob / 100.0));
        double phi_rad = acos(phi_energy);
        std::complex<double> phase = std::polar(1.0, phi_rad);

        ket input = amp0 * 0_ket + amp1 * phase * 1_ket;
        QCircuit qc{1};
        qc.gate(gt.H, 0); // Appliquer une porte Hadamard

        QEngine engine{qc};
        engine.set_state(input);
        engine.execute();

        return engine.get_state();
    }

public:
    // Constructeur avec HEX directement
    QuantumColor(const std::string& hex) {
        set_color(50, 0.0, hex); // Initialisation neutre par défaut
    }

    // Constructeur pour combiner deux couleurs avec pondération
    QuantumColor(const QuantumColor& c1, const QuantumColor& c2, double weight1 = 1.0, double weight2 = 1.0) {
        double total_weight = weight1 + weight2;
        double norm_weight1 = weight1 / total_weight;
        double norm_weight2 = weight2 / total_weight;

        double combined_prob = (c1.probability * norm_weight1 + c2.probability * norm_weight2);
        double combined_phi_energy = (c1.phi_energy * norm_weight1 + c2.phi_energy * norm_weight2);
        int r = (std::stoi(c1.color_hex.substr(0, 2), nullptr, 16) * norm_weight1 +
                 std::stoi(c2.color_hex.substr(0, 2), nullptr, 16) * norm_weight2);
        int g = (std::stoi(c1.color_hex.substr(2, 2), nullptr, 16) * norm_weight1 +
                 std::stoi(c2.color_hex.substr(2, 2), nullptr, 16) * norm_weight2);
        int b = (std::stoi(c1.color_hex.substr(4, 2), nullptr, 16) * norm_weight1 +
                 std::stoi(c2.color_hex.substr(4, 2), nullptr, 16) * norm_weight2);

        set_color(combined_prob, combined_phi_energy, to_hex(r, g, b));
    }

    // Initialisation avec probabilités et phase énergétique
    void set_color(double prob, double phi_energy, const std::string& hex) {
        probability = prob;
        this->phi_energy = phi_energy;

        // Calcul des amplitudes et angles
        double amp = sqrt(prob / 100.0);
        theta = 2 * acos(amp) * 180 / M_PI;
        double phi_rad = acos(phi_energy);
        phi = phi_rad * 180 / M_PI;

        // Création de l'état quantique avec circuit
        state = calculate_ket(prob, phi_energy);

        // Attribution directe de la couleur HEX
        color_hex = hex;
    }

    // Méthodes pour ajuster l'état avec un pourcentage
    void setConstructif(double percent = 1.0) {
        set_color(probability, 1.0 * percent, color_hex);
    }

    void setDestructif(double percent = 1.0) {
        set_color(probability, -1.0 * percent, color_hex);
    }

    // Combiner avec un poids
    QuantumColor combine(const QuantumColor& other, double weight1 = 1.0, double weight2 = 1.0) const {
        return QuantumColor(*this, other, weight1, weight2);
    }

    // Affichage des informations
    void display(const std::string& label) const {
        std::cout << label << " :\n";
        std::cout << "----------------------------------------------------------------\n";
        std::cout << "| Prob (%) | Amp. | θ (°) | φ (°) | φ Energy | Interaction          | Hex       |\n";
        std::cout << "----------------------------------------------------------------\n";

        std::string interaction;
        if (phi_energy == 2) interaction = "Constructif (Blanc)";
        else if (phi_energy == -2) interaction = "Destructif (Noir)";
        else if (phi_energy > 0) interaction = "Constructif Partiel";
        else if (phi_energy < 0) interaction = "Destructif Partiel";

        std::cout << "| " << std::setw(9) << probability
                  << " | " << std::setw(5) << sqrt(probability / 100.0)
                  << " | " << std::setw(5) << theta
                  << " | " << std::setw(5) << phi
                  << " | " << std::setw(9) << phi_energy
                  << " | " << std::setw(20) << interaction
                  << " | " << color_hex << " |\n";

        std::cout << "----------------------------------------------------------------\n\n";
    }
};

// -------------------------------------------------------------
// Fonction principale
// -------------------------------------------------------------
int main() {
    // Création des couleurs initiales
    Qrn red("FF0000", size, 3);   // Rouge mais defini ses possibilité a 16777216 couleur que le qbit peu prendre répartie en 3 quatil 
    Qrn blue("0000FF", size, 3); // Bleu

    // Affichage des états initiaux

displayHex(red.gethex() // récuperer la valeur final entre range min et range max et donne sa valeur en hexadecimal si il y a plusieurs quartil faire en sorte de les prendre en compte car le calcule ne sera pas le meme car chaque quartil contient ses propre donné la l'idée serait de du coup convertir r g b vue qu'il y a 3 quartil et donc me donné la bonne couleur pareille si je le setRange(0, 8, 3) met en 8 bit les couleur et déplace correctement la donné pour que si j'ai du rouge j'ai le meme rouge mais en 8bits donc de la perte de donné possible  mais c'est ce qu'on veux 
    red.display("Rouge (Initial)");
    blue.display("Bleu (Initial)");

    // Exemple de combinaisons avec constructeur
    Qrn combined = red.combine(blue, 150% red, 300% bleu); normalisation pour avoir le bon % mais permet de faire des calcule plus complexe
    combined.display("Rouge + Bleu (Combinaison)");


    // Modification de l'état avec pourcentage
    red.setConstructif(80);

    blue.setDestructif(0.5);

    Qrn weighted = red.combine(blue, 50, 50);

    return 0;
}


mais il y un problemment dans ma logique si les couleur 8bits c'est 256 pour un total de 16,8 milion de couleur la actuellement en faisant 255, 1 on met juste 255 couleur possible sur 1 quartil donc il y a un problemme maintenant si je fais "FF0000", size, 3 je suis censé avoir 16777216 possibilité

actuellement j'ai un code simple mais je voudrais l'appeler Qrn et faire en sorte qu'il garde setConstructif etc pour ses interaction c'est important juste rajouté un set neutre et je veux les 3 en % float donc 80% ou 50 pour 50% je veux absolument que les interaction se fasse grace a qengine directement et les qbit stoqué avec ket la class Qrn n'a aucun rapport avec les couleur et est seulement du stockage d'une donné par rapport a une range puis d'un parser pour obtenir la valeur en fonction du contenu du parser dans les exemple c'est de la couleur qui est utiliser mais plus tard l'idée serait plutot de pouvoir l'utiliser avec des mots ou autre par exemple stoquer les minuscule sur le premier quartir puis les majuscule sur le second puis les chiffre sur un troisiemme et pourquoi pas des caractere speciaux mais pour le moment je veux juste des couleur c'est plus représentatif mais garde a l'idée pour que la logique s'éxecute a n'importe quelle type de donné et intégre directement le parser dans sa class autant pour definir Qrn avec "FF0000", size, quartil de base si je fais couleur melange couleur je dois avoir la couleur du mélange donc de base la couleur est normal ni destrutif ou autre et seulement si je fais  q2.destructif(50%) la elle se positionnera pour devenir destrutif a 50%:

ok reprend de 0 tu me fais le meme code depuis tout a l'heure et je ne l'aime pas oublie tout et on reprend garde juste les problématique en tete car ce sera les meme je veux definir avec red("FF0000"//convertie en point sur la sphere de bosh en fonction de size : 0, 256 et quartil 3 qui donne 16777216 possibilité

l'idée est que si je fais Qrn char_c('a'//converti en point sur la sphere, 0, 127); // se defini par defaut a 1 si aucun quartil est mis et je pourrais convertir a par autre chose mais le mieux serait de creer ma propre table ascci en qbit par exemple en faisant que a z soit 0 25 premier quartil  0 25 second quartil et 10 troisiemme quartil comme ca je pourrais literramement avoir le type de donné avec les étage que je veux et leurs inverse fonctionnerais toujours donc a deviendrais z avec une rotation de quartil je pourrais avoir que a est aussi A et avec une autre A est aussi 0