#include "def.hpp"
#include "class.hpp"

#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include "qpp/qpp.hpp"

using namespace qpp;

// -------------------------------------------------------------
// Classe Qsym - Gestion des symétries et étiquettes
// -------------------------------------------------------------
class Qsym {
private:
    std::string label;                                  // Nom de la symétrie
    std::map<int, int> symmetry_map;                     // Map des symétries
    std::map<int, std::string> symbols;                  // Map des symboles associés
    int min_val, max_val;                                // Limites de la plage

public:
    // Constructeur
    Qsym(const std::string& label, int min_val, int max_val)
        : label(label), min_val(min_val), max_val(max_val) {}

    // Ajouter une symétrie
    void add(int start, int end) {
        for (int i = start; i <= end; ++i) {
            int symmetric = end - (i - start);
            symmetry_map[i] = symmetric; // Symétrie réversible
        }
    }

    // Ajouter un symbole
    void addSymbol(int value, const std::string& symbol) {
        symbols[value] = symbol;
    }

    // Encoder une valeur
    double encode(int value) const {
        return static_cast<double>(value - min_val) / (max_val - min_val); // Normalisation 0-1
    }

    // Décoder une valeur
    int decode(double value) const {
        return static_cast<int>(round(value * (max_val - min_val))) + min_val;
    }

    std::string getLabel() const { return label; }
};

// -------------------------------------------------------------
// Classe Qencode - Encodeur dynamique basé sur des symétries
// -------------------------------------------------------------
class Qencode {
private:
    std::vector<Qsym> symmetries; // Liste des symétries possibles

public:
    // Ajouter une symétrie
    void addSymmetry(const Qsym& sym) {
        symmetries.push_back(sym);
    }

    // Encoder une valeur RGB
    double encodeRGB(int r, int g, int b) const {
        double scale = 1.0 / 3.0;
        return (symmetries[0].encode(r) * scale) +
               (symmetries[0].encode(g) * scale * 2) +
               (symmetries[0].encode(b) * scale * 3);
    }

    // Décoder une valeur RGB
    std::tuple<int, int, int> decodeRGB(double value) const {
        double scale = 1.0 / 3.0;
        int r = symmetries[0].decode(value / scale);
        int g = symmetries[0].decode(fmod(value, scale * 2) / scale);
        int b = symmetries[0].decode(fmod(value, scale * 3) / scale);
        return {r, g, b};
    }
};

// -------------------------------------------------------------
// Classe Qrn - Représentation quantique
// -------------------------------------------------------------
class Qrn {
private:
    double theta;
    double phi;
    ket state;
    double value; // Utilisation d'un float pour éviter les dépassements

    ket calculate_ket(double theta, double phi) const {
        double amp0 = cos(theta / 2);
        std::complex<double> amp1 = sin(theta / 2) * std::polar(1.0, phi);
        return amp0 * 0_ket + amp1 * 1_ket;
    }

public:
    // Constructeur
    Qrn() : theta(0.0), phi(0.0), value(0.0) {
        state = calculate_ket(theta, phi);
    }

    // Définir la valeur avec encodage
    void set(double v) {
        value = v;
        theta = value * M_PI; // Étalement sur 0-1 → 0-180°
        phi = 0.0;
        state = calculate_ket(theta, phi);
    }

    // Obtenir la valeur
    double getValue() const { return value; }

    // Affichage
    void display() const {
        std::cout << "Theta: " << (theta * 180 / M_PI) << "°, Phi: " << (phi * 180 / M_PI)
                  << "°, Value: " << value << std::endl;
    }
};

// -------------------------------------------------------------
// Fonction principale - Tests
// -------------------------------------------------------------
int main() {
    // Initialiser la symétrie RGB
    Qsym rgb("rgb", 0, 255);

    // Initialiser l'encodeur
    Qencode encoder;
    encoder.addSymmetry(rgb);

    // Encoder une valeur RGB (Rouge : 255, 0, 0)
    double encodedRGB = encoder.encodeRGB(255, 0, 0);
    std::cout << "Encoded RGB: " << encodedRGB << std::endl;

    auto [r, g, b] = encoder.decodeRGB(encodedRGB);
    std::cout << "Decoded RGB: " << r << ", " << g << ", " << b << std::endl;

    // Créer un qubit et afficher l'état
    Qrn qubit;
    qubit.set(encodedRGB);
    qubit.display();

    return 0;
}
