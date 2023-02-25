//
//  Ex45.h
//  TME9
//
//  Created by Bogouslavsky Illia on 23/01/2023.
//

#ifndef Ex45_h
#define Ex45_h

#include <stdio.h>
#include "Ex44.h"

element_t *Ajout_ensemble_trie(element_t *ensemble,int val, int freq);
element_t *Supprime_total_element_ensemble_trie(element_t *ensemble, int val);
element_t *Supprime_element_ensemble_trie(element_t *ensemble, int val);

#endif /* Ex45_h */
