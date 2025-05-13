#ifndef PARTICULEA_HPP
#define PARTICULEA_HPP

#include <iostream>
#include <fstream>

class ParticuleA {
private:
    double masse, x, y, vx, vy, fx, fy;

public:
    ParticuleA(double m, double xp, double yp, double vxp, double vyp);

    double getMasse() const;
    double getX() const;
    double getY() const;
    double getVx() const;
    double getVy() const;
    double getFx() const;
    double getFy() const;

    ParticuleA updatedPosition(double dt) const;
    ParticuleA updatedVitesse(double dt, double old_fx, double old_fy) const;
    ParticuleA updatedForce(double new_fx, double new_fy) const;

    std::string toString() const;
    std::string toConsoleString() const;
};

#endif
