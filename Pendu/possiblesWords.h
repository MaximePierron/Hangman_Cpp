#pragma once

#include <vector>
#include <string>

using namespace std;

const vector<string> possibleWords{ "TONUS", "LIEGE", "SABLE", "SAUNA", "RHUME", "DIEUX", "TACHE", "BANJO", "SUCRE", "CAPOT", "FRISE", "EMAIL", "LASER", "ECHEC",
                            "GLACON", "FRIMER", "COULIS", "JAUGER", "CRAMPE", "RANCIR", "DEFIER", "MORUES", "CIMENT", "JOUJOU", "DESSIN", "PIMENT",
                            "GESTION", "COULEUR", "DOMPTER", "PAPYRUS", "HAUTAIN", "RONFLER", "TACTILE", "SPOLIER", "DOYENNE", "COUVENT", "GLACIER",
                            "EPLUCHER", "ORPHELIN", "ENSABLER", "LEGITIME", "CHARMEUR", "RAYONNER", "BATONNET", "GRILLAGE", "ENDOSSER", "ANCIENNE" };

const int POSSIBLE_WORDS_SIZE = static_cast<int>(possibleWords.size());
