#include "def.hpp"
#include "class.hpp"

#include <iostream>     
#include <cmath>        
#include <iomanip>      
#include "qpp/qpp.hpp"  

using namespace qpp;    

// -------------------------------------------------------------
// Fonction : Crée un état quantique (ket) avec une probabilité donnée
// -------------------------------------------------------------
ket create_psi(double prob) {
    double amp1 = sqrt(prob / 100.0);           // Amplitude sur |1⟩
    double amp0 = sqrt((100.0 - prob) / 100.0); // Amplitude sur |0⟩
    return amp0 * 0_ket + amp1 * 1_ket;
}

// -------------------------------------------------------------
// Fonction : Affiche les résultats sous forme de tableau
// -------------------------------------------------------------
void display_table(const std::string& label, const ket& state, bool show_total = false) {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << label << " :\n";
    std::cout << "------------------------------------------------------\n";
    std::cout << "| État | Probabilité (%) | Amplitude | θ (°) | φ (°) |\n";
    std::cout << "------------------------------------------------------\n";

    // Variables pour les totaux
    double total_prob = 0.0;
    double total_amplitude = 0.0;
    double avg_theta = 0.0;
    double avg_phi = 0.0;

    // Boucle sur chaque état
    for (idx i = 0; i < state.size(); ++i) {
        double prob = std::norm(state[i]) * 100;       // Probabilité
        double amplitude = std::abs(state[i]);         // Amplitude
        double theta = 2 * acos(amplitude) * 180 / M_PI; // Angle θ
        double phi = atan2(std::imag(state[i]), std::real(state[i])) * 180 / M_PI; // Angle φ

        if (phi < 0) phi += 360; // φ dans [0°, 360°]

        total_prob += prob;
        total_amplitude += amplitude;
        avg_theta += theta * prob / 100.0; // Moyenne pondérée
        avg_phi += phi * prob / 100.0;

        // Affichage
        std::cout << "|  " << i << "   | " << prob << "               | "
                  << amplitude << "       | " << theta << "   | " << phi << " |\n";
    }

    std::cout << "------------------------------------------------------\n";

    // Affiche les totaux si demandé
    if (show_total) {
        double avg_amplitude = total_amplitude / state.size(); // Amplitude moyenne
        double total_theta = 2 * acos(avg_amplitude) * 180 / M_PI; // Recalcul précis de θ
        total_theta = round(total_theta); // Arrondi final
        avg_phi = round(avg_phi);         // Arrondi final de φ

        std::cout << "| Total\n";
        std::cout << "------------------------------------------------------\n";
        std::cout << "|  0.5 | 0.5               | " 
                  << avg_amplitude << "       | "
                  << total_theta << "   | " << avg_phi << " |\n";
        std::cout << "------------------------------------------------------\n\n";
    }
}

// -------------------------------------------------------------
// Fonction : Combine deux états et applique un circuit quantique
// -------------------------------------------------------------
ket combine_and_calculate(const ket& psi1, const ket& psi2) {
    // Étape 1 : Combinaison équilibrée des états
    ket combined = (psi1 + psi2) / sqrt(2);

    // Étape 2 : Normalisation
    combined /= norm(combined);

    // Étape 3 : Circuit Hadamard
    QCircuit qc{1};
    qc.gate(gt.H, 0);

    // Étape 4 : Exécution du moteur quantique
    QEngine engine{qc};
    engine.set_state(combined); 
    engine.execute();           

    return engine.get_state(); 
}

// -------------------------------------------------------------
// Fonction principale
// -------------------------------------------------------------
int main() {
    // Création des états initiaux
    ket psi1 = create_psi(50);  
    ket psi2 = create_psi(50);  

    // Affichage des états initiaux
    std::cout << "ÉTATS INITIAUX :\n";
    display_table("Psi 1", psi1, true);
    display_table("Psi 2", psi2, true);

    // Calcul de l'état final
    ket psi_res = combine_and_calculate(psi1, psi2);

    // Affichage du résultat final
    std::cout << "ÉTAT FINAL APRÈS CALCUL :\n";
    display_table("Psi Résultant", psi_res, true);

    return 0; 
}