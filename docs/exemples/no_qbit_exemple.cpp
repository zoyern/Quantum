#include <cmath>

#include <iostream>
#include <complex>
#include <Eigen/Dense>

// Définition de la classe Qrn
class Qrn {
private:
    qpp::ket qubit_state; // État du qubit représenté comme un vecteur colonne

public:
    // Constructeur
    Qrn(double percentage, std::complex<double> intensity = {1.0, 0.0}) {
        // Validation du pourcentage
        if (percentage < 0.0 || percentage > 100.0) {
            throw std::invalid_argument("Le pourcentage doit être compris entre 0 et 100.");
        }

        // Calcul des amplitudes en fonction du pourcentage
        double prob1 = percentage / 100.0;      // Probabilité de |1⟩
        double prob0 = 1.0 - prob1;             // Probabilité de |0⟩

        // Amplitudes correspondantes
        std::complex<double> alpha = std::sqrt(prob0) * intensity;
        std::complex<double> beta = std::sqrt(prob1) * intensity;

        // Normalisation de l'état du qubit
        double norm = std::sqrt(std::norm(alpha) + std::norm(beta));
        alpha /= norm;
        beta /= norm;

        // Initialisation de l'état du qubit
        qubit_state = qpp::ket::Zero(2);
        qubit_state(0) = alpha;
        qubit_state(1) = beta;
    }

    // Méthode pour obtenir l'état du qubit
    qpp::ket get_state() const {
        return qubit_state;
    }

    // Surcharge de l'opérateur d'addition pour combiner les états de deux qubits
    Qrn operator+(const Qrn& other) const {
        qpp::ket combined_state = qubit_state + other.get_state();
        // Normalisation du nouvel état
        combined_state /= combined_state.norm();
        Qrn result(0); // Création d'un Qrn temporaire
        result.qubit_state = combined_state;
        return result;
    }

    // Méthode pour afficher les probabilités des états |0⟩ et |1⟩
    void display_probabilities() const {
        double prob0 = std::norm(qubit_state(0));
        double prob1 = std::norm(qubit_state(1));
        std::cout << "Probabilité de mesurer |0⟩ : " << prob0 * 100 << "%" << std::endl;
        std::cout << "Probabilité de mesurer |1⟩ : " << prob1 * 100 << "%" << std::endl;
    }
};

int main() {
    try {
        // Création de deux qubits avec des pourcentages et intensités spécifiques
        Qrn qubit1(75.0, {1.0, 0.0}); // 30% |1⟩, intensité 1+0i
        Qrn qubit2(25.0, {1.0, 0.0}); // 50% |1⟩, intensité 1+0i

        // Affichage des probabilités initiales
        std::cout << "Qubit 1 :" << std::endl;
        qubit1.display_probabilities();
        std::cout << "Qubit 2 :" << std::endl;
        qubit2.display_probabilities();

        // Addition des deux qubits
        Qrn combined_qubit = qubit1 + qubit2;

        // Affichage des probabilités après combinaison
        std::cout << "Qubit combiné :" << std::endl;
        combined_qubit.display_probabilities();
    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}


