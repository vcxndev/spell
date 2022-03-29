#include "spell.h"

bool isVowel(char& ch) {
	switch (ch) {
	case 'A':
		return true;
	case 'E':
		return true;
	case 'I':
		return true;
	case 'İ':
		return true;
	case 'O':
		return true;
	case 'Ö':
		return true;
	case 'U':
		return true;
	case 'Ü':
		return true;

	case 'a':
		return true;
	case 'e':
		return true;
	case 'ı':
		return true;
	case 'i':
		return true;
	case 'o':
		return true;
	case 'ö':
		return true;
	case 'u':
		return true;
	case 'ü':
		return true;

	default:
		return false;
	}
}

std::vector<std::string> spell(char* word) {
	size_t w_length = strlen(word);
	unsigned int vo_c = 0; 

	for (unsigned int i = 0; i < w_length; ++i) {
		if (isVowel(word[i])) {
			++vo_c;
		}
	}

	std::string tmp;
	std::vector<std::string> syllabes;

	for (int i = w_length - 1; i > -1; --i) {
		if (vo_c == 0) {
			if (syllabes.empty()) {
				syllabes.push_back(std::string(word));
				break;
			}
			else {
				for(; i > -1; --i){
					tmp.push_back(word[i]);
				}
				reverse(tmp.begin(), tmp.end());
				syllabes[syllabes.size() - 1].insert(0, tmp);
			}
		}
		else {
			tmp.push_back(word[i]);
			if (isVowel(word[i])) {
				vo_c--;
				if (!isVowel(word[i - 1])) {
					tmp.push_back(word[--i]);
				}
				reverse(tmp.begin(), tmp.end());
				syllabes.push_back(tmp);
				tmp.clear();
			}
		}
	}
	reverse(syllabes.begin(), syllabes.end());
	return syllabes;
}
