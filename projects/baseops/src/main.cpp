#include "def.hpp"
#include "class.hpp"

#include <iostream>
#include <cmath>
#include <iomanip>
#include "qpp/qpp.hpp"

using namespace qpp;

// Fonction pour créer un photon avec intensité et phase
ket create_photon(double intensity, double phi_energy) {
    double amp = sqrt(intensity / 100.0);
    double phi_rad = acos(phi_energy); // Conversion en radians
    std::complex<double> phase = std::polar(1.0, phi_rad);
    return amp * phase * 1_ket;
}

// Fonction pour simuler une interaction avec la map
ket interact_with_map(const ket& photon, double reflection) {
    QCircuit qc{1};
    if (reflection > 0) {
        qc.gate(gt.Z, 0); // Applique un décalage de phase de 180°
    } else {
        qc.gate(gt.H, 0); // Équilibre en superposition
    }

    QEngine engine{qc};
    engine.set_state(photon);
    engine.execute();
    return engine.get_state();
}

int main() {
    // Photon initial (90% intensité, aligné)
    ket photon = create_photon(90, 1.0);

    // Interaction avec un mur (réflexion)
    ket result = interact_with_map(photon, 1);

    // Affichage du résultat
    std::cout << "Amplitude finale : " << std::abs(result[0]) << "\n";
    std::cout << "Phase finale (rad) : " << std::arg(result[0]) << "\n";
    return 0;
}
