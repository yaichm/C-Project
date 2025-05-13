#include "ParticuleA.hpp"

ParticuleA::ParticuleA(double m, double xp, double yp, double vxp, double vyp)
    : masse(m), x(xp), y(yp), vx(vxp), vy(vyp), fx(0), fy(0) {}

double ParticuleA::getMasse() const { return masse; }
double ParticuleA::getX() const { return x; }
double ParticuleA::getY() const { return y; }
double ParticuleA::getVx() const { return vx; }
double ParticuleA::getVy() const { return vy; }
double ParticuleA::getFx() const { return fx; }
double ParticuleA::getFy() const { return fy; }

ParticuleA ParticuleA::updatedPosition(double dt) const {
    double new_x = x + dt * (vx + 0.5 * fx / masse * dt);
    double new_y = y + dt * (vy + 0.5 * fy / masse * dt);

    return ParticuleA(masse, new_x, new_y, vx, vy); // même vitesse et masse
}

ParticuleA ParticuleA::updatedVitesse(double dt, double old_fx, double old_fy) const {
    double new_vx = vx + dt * 0.5 / masse * (fx + old_fx);
    double new_vy = vy + dt * 0.5 / masse * (fy + old_fy);
    ParticuleA updated(*this);
    updated.vx = new_vx;
    updated.vy = new_vy;
    return updated;
}


ParticuleA ParticuleA::updatedForce(double new_fx, double new_fy) const {
    ParticuleA updated(*this);
    updated.fx = new_fx;
    updated.fy = new_fy;
    return updated;
}

std::string ParticuleA::toString() const {
    return std::to_string(x) + " " + std::to_string(y) + "\n";
}

std::string ParticuleA::toConsoleString() const {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}
