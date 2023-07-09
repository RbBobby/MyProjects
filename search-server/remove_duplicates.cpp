#include "remove_duplicates.h"

void RemoveDuplicates(SearchServer& search_server)
{
	vector<int> ids_; //буфер для id, которые нужно будет удалить, так как в первом цикле удаление приведет к изменению проходимого файла
	set<set<string>> id_words;
	set<string> words;

	for (const auto& id_1 : search_server) {
	
		for (const auto& c : search_server.GetWordFrequencies(id_1)) {
			words.insert(c.first);
		}
		if (!id_words.count(words)) {
			id_words.insert(words);
		}
		else {
			cout << "Found duplicate document id " << id_1 << endl;
			ids_.push_back(id_1);
		}
		words.clear();
	}
	for (const auto& id : ids_) {
		search_server.RemoveDocument(id);
	}
}
