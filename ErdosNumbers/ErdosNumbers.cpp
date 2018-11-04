#include <cstdlib>
#include <iostream>
#include <ios>
#include <cstdio>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int main() {
    int scenario;
    scanf("%d", &scenario);

    for(int i = 0; i < scenario; i++){
	int papers, people;
	cout << "Scenario " << i+1 << endl;
	scanf("%d%d", &num_papers, &num_people);
	
	vector<string> list_people;
	int people_numbers[num_papers];

	for(int i = 0; i < num_papers; i++){
	    string papers;
	    scanf("%[^\n]", &papers);
	    
	    string person;
	    int size = papers.size();
	    int num = 0;
	    for(int j = 0; j < size; j++){
		if(papers[j] == ',' && num == 1){
		    num = 0;
		    list_people.push_back(person);
		    person = "";
		}
		else if(papers[j] == ':'){
		    list_people.push_back(person);
		    person = "";
		    break;
		}
		else if(papers[j] == ',' && num != 1){
		    num++;
		    person += papers[j];
		}
		else
		    person += papers[j];
	    }
	    people_numbers[i] = list_people.size();
	}
	
	
	string people[num_people];
	for(int i = 0; i < num_people; i++){
	    scanf("%[^\n]", &people[i]);
	    
	}
	
	
	
	
    }
    return 0;
}
