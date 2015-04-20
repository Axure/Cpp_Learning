#include <iostream>
#include <vector>

struct Compare {
    bool operator()(const std::string& first, const std::string& second) {
        return first.size() > second.size();
    }
};

int main(int argc, char const *argv[])
{
	int N; std::cin >> N;
	std::vector<std::string> strings;
	std::string baseString;

	for(int i = 0; i < N; ++i)
	{
		std::cin >> baseString;
		strings.push_back(baseString);

	}
	std::cin >> baseString;
	Compare compareString;
	std::sort(strings.begin(), strings.end(), compareString);

	std::size_t found;

	for(std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); ++it)
	{
		std::cout << *it << std::endl;
	}

	for(int i = 0; i < baseString.length(); ++i)
	{
		for(std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); ++it)
		{
			found = baseString.find(*it);
			if (found == 0)
			{
				std::cout << *it;
				i += (*it).length() - 1;
				std::cout << (*it).length() - 1;
				break;
			}
		}
		std::cout << "broken";
		if (found != 0) std::cout << baseString[i];
		if (i != baseString.length() - 1)
		{
			std::cout << " ";
		}
	}

	return 0;
}