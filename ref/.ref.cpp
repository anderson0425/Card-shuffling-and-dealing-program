
//Return by value
vector<int> myFunction(vector<int> &results){
    vector <int> even_vector;
    for (const auto &i : results) {
        if(i%2==0){
            even_vector.push_back(i);
        }
    }
   return even_vector;
}
 
int main(){
   vector<int> vec={20, 51, 11, 88, 44, 77, 14, 99};
   vector<int> even_vect=myFunction(vec);
   print_vector(even_vect);
}












//Return by reference
vector<int> & myFunction(vector<int> &results){
    for ( auto &i : results) {
        i*=i;
    }  
   return results;
}
 
int main(){
   vector<int> vec={20, 51, 11, 88, 44, 77, 14, 99};
   vector<int> vect=myFunction(vec);
   print_vector(vect);
}
 