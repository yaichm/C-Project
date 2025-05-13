#include "StormerVerlet.hpp"

const double G = 1.0;

std::vector<std::pair<double, double>> StormerVerlet::force_grav(const std::vector<ParticuleA> &parList, int n) {
    std::vector<std::pair<double, double>> forces(n);
    double fx, fy, mi, mj, dxi, dyi, dx, dy, r, f;

    for (int i = 0; i < n; i++) {
        fx = fy = 0;
        mi = parList[i].getMasse();
        dxi = parList[i].getX();
        dyi = parList[i].getY();

        for (int j = 0; j < n; j++) {
            if (j != i) {
                mj = parList[j].getMasse();
                dx = dxi - parList[j].getX();
                dy = dyi - parList[j].getY();
                r = dx * dx + dy * dy;
                f = (G * mi * mj) / (r * sqrt(r));

                fx += f * dx;
                fy += f * dy;
            }
        }
        forces[i] = {fx, fy};  // stocke les forces
    }

    return forces;
}


std::vector<std::vector<std::pair<double, double>>> StormerVerlet::algoStr(double dt, double dfin, std::vector<ParticuleA> parList) {
    double t_init = 0;
    int n = parList.size();
    std::vector<std::vector<std::pair<double, double>>> all_positions;

    while (t_init < dfin) {
        std::vector<double> old_fx(n), old_fy(n);
        std::vector<std::pair<double, double>> positions_t;

        // Calcul des forces
        std::vector<std::pair<double, double>> forces = this->force_grav(parList, n);
        for (int i = 0; i < n; ++i) {
            parList[i] = parList[i].updatedForce(forces[i].first, forces[i].second);
        }

        // Mise à jour du temps
        t_init += dt;

        // Mise à jour des positions + stockage des anciennes forces + enregistrement
        for (int i = 0; i < n; ++i) {
            old_fx[i] = parList[i].getFx();
            old_fy[i] = parList[i].getFy();
            parList[i] = parList[i].updatedPosition(dt);
            positions_t.emplace_back(parList[i].getX(), parList[i].getY());
        }

        // Recalcul des forces après mise à jour de la position
        forces = this->force_grav(parList, n);
        for (int i = 0; i < n; ++i) {
            parList[i] = parList[i].updatedForce(forces[i].first, forces[i].second);
        }

        // Mise à jour des vitesses
        for (int i = 0; i < n; ++i) {
            parList[i] = parList[i].updatedVitesse(dt, old_fx[i], old_fy[i]);
        }

        // Enregistrer les positions de cette étape
        all_positions.push_back(positions_t);
    }

    return all_positions;
}

