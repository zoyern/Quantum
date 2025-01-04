

#include <iostream> // Inclusion de la bibliothèque pour l'affichage standard
#include "qpp/qpp.h" // Inclusion de la bibliothèque Quantum++ pour manipuler les états quantiques

using namespace qpp; // Utilisation de l'espace de noms qpp pour accéder directement aux fonctions et objets Quantum++

// Fonction pour créer un état personnalisé
ket create_custom_state(double prob1, double prob2, double intensity1, double intensity2) {
    // Création de deux états quantiques personnalisés
    // prob1 et prob2 sont les probabilités souhaitées (en pourcentage, par exemple 75% et 25%)
    // intensity1 et intensity2 contrôlent les amplitudes de chaque état

    // Étape 1 : Calcul des amplitudes à partir des probabilités
    double amp1 = sqrt(prob1 / 100.0); // Amplitude pour le premier état, racine carrée de la probabilité
    double amp2 = sqrt(prob2 / 100.0); // Amplitude pour le second état

    // Étape 2 : Création des états quantiques de base |1⟩ avec des amplitudes
    ket psi1 = amp1 * intensity1 * 1_ket; // |1⟩ avec une amplitude pondérée par intensity1
    ket psi2 = amp2 * intensity2 * 1_ket; // |1⟩ avec une amplitude pondérée par intensity2

    // Pourquoi multiplier par les intensités ?
    // Les intensités permettent de contrôler la contribution relative de chaque état dans la combinaison.

    // Étape 3 : Combinaison linéaire des deux états
    ket combined = psi1 + psi2; // Combine les deux états en un seul vecteur

    // Pourquoi additionner les états ?
    // En mécanique quantique, les états peuvent être superposés, ce qui signifie qu'on peut représenter plusieurs configurations simultanément.

    // Étape 4 : Normalisation
    combined /= norm(combined); // Normalise pour que la somme des probabilités soit égale à 1.

    // Pourquoi normaliser ?
    // La norme garantit que l'état est physiquement valide : en mécanique quantique, la somme des probabilités doit être 1.
    // Si combined était nul, la division par zéro échouerait. La normalisation empêche cela.

    return combined; // Retourne l'état combiné normalisé
}

int main() {
    // Créer l'état personnalisé avec 75% et 25% de probabilités et intensité 1 pour chaque état
    ket psi = create_custom_state(75, 25, 1, 1);

    // Étape 5 : Visualisation de l'état initial
    std::cout << "État initial (avant circuit) :\n";
    for (idx i = 0; i < psi.size(); ++i) { // idx est un type entier non signé défini par Quantum++ pour les indices
        double prob = std::norm(psi[i]) * 100; // Probabilité associée à chaque composante
        std::cout << disp(psi[i]) << " (" << prob << "%)\n"; // Affiche chaque amplitude avec son pourcentage
    }

    // Création d'un circuit quantique
    QCircuit qc{1}; // Initialise un circuit avec 1 qubit
    // Pourquoi 1 ?
    // Le nombre spécifié représente le nombre de qubits dans le circuit. On pourrait par exemple mettre 2 ou plus pour des systèmes multi-qubits.
    // Exemple : QCircuit qc{2}; définit un circuit avec 2 qubits.

    // Ajouter une porte Hadamard (H) au qubit 0
    qc.gate(gt.H, 0); // Applique une transformation Hadamard au qubit 0
    // Visuellement, cette transformation place l'état dans une superposition équilibrée (50%-50%).

    // Initialiser QEngine pour exécuter le circuit
    QEngine engine{qc}; // L'objet QEngine est utilisé pour exécuter les instructions définies dans qc.

    // Pourquoi QEngine et pas QCircuit directement ?
    // QCircuit définit simplement le circuit, tandis que QEngine exécute réellement le circuit sur un état donné.

    // Définir l'état initial personnalisé dans l'engin quantique
    engine.set_state(psi); // Définit l'état initial combiné calculé précédemment.

    // À quoi sert set_state ?
    // Cette méthode permet de définir un état personnalisé comme point de départ, au lieu de partir d'un état par défaut |0⟩.

    // Étape 6 : Exécuter le circuit
    engine.execute(); // Exécute les opérations définies dans qc sur l'état initial.

    // execute() possède-t-il des paramètres ?
    // Non, mais on peut exécuter un circuit plusieurs fois pour des statistiques en répétant l'appel (ex. dans une boucle).

    // Étape 7 : Récupérer l'état final
    auto final_state = engine.get_state(); // Récupère l'état après l'exécution du circuit

    // get_state() possède-t-il des paramètres ?
    // Non, il retourne simplement l'état actuel après l'exécution. Pour des informations statistiques, il faut utiliser des mesures explicites.

    // Étape 8 : Afficher l'état final avec probabilités
    std::cout << "État final (après circuit) :\n";
    for (idx i = 0; i < final_state.size(); ++i) { // idx représente les indices du vecteur
        double prob = std::norm(final_state[i]) * 100; // Calcule les probabilités en pourcentage
        std::cout << disp(final_state[i]) << " (" << prob << "%)\n"; // Affiche chaque amplitude avec son pourcentage
    }

    // Pourquoi utiliser disp et non measure ?
    // disp est utile pour afficher directement l'état complet, alors que measure serait utilisé pour simuler une mesure avec probabilités d'observer un résultat.

    return 0; // Fin du programme
}

