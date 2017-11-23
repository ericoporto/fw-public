#include <iostream>
#include <iomanip>

#include "FilmicCurve/FilmicColorGrading.h"

int main(int argc, char *argv[]) {
    static const int curveLen = 256;

	FilmicColorGrading::UserParams userParams; // User params are the input
    userParams.m_filmicToeStrength = 0.5;
    userParams.m_filmicToeLength = 0.5;
    userParams.m_filmicShoulderStrength = 2.0;
    userParams.m_filmicShoulderLength = 0.5;
    userParams.m_filmicShoulderAngle = 1.0;

	FilmicColorGrading::RawParams rawParams;
    FilmicColorGrading::EvalParams evalParams;
    FilmicColorGrading::BakedParams bakeParams;

	FilmicColorGrading::RawFromUserParams(rawParams, userParams); FilmicColorGrading::EvalFromRawParams(evalParams,rawParams);
    FilmicColorGrading::BakeFromEvalParams(bakeParams,evalParams,curveLen,FilmicColorGrading::kTableSpacing_Quadratic);

    for(int i = 0; i < curveLen; i++) {
        float v = (float)i / (curveLen - 1);
        std::cout
            << std::fixed
            << std::setprecision(3)
            << v
            << ","
            << bakeParams.m_curveG[i]
            << std::endl;
    }
}
