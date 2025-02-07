// ********************************** AWengine **************************************** //
//                                                                                      //
//  purpose: tools for engine such as read file, split for obj parser, obj parser etc.  //
//                                                                                      //        
// ************************************************************************************ //


#include  "devtools.hpp"

char*  filereader  ( const char* filename ) {

    std::cout << filename << std::endl;

    FILE* file = fopen(filename, "r");

    if (!file) {    perror("ERROR to open");    return NULL;    }

    fseek(file, 0, SEEK_END);

    long file_size = ftell(file);

    rewind(file);

    char* buffer = (char*)malloc((file_size + 1) * sizeof(char));

    if (!buffer) {    perror("ERROR to allocate memory");     fclose(file);      return NULL;    }

    size_t read_size = fread(buffer, 1, file_size, file);

    if (read_size != file_size) {   perror("ERROR reading file");   free(buffer);   fclose(file);   return NULL;    }

    buffer[read_size] = '\0';

    fclose(file);

    return buffer;

}

std::vector<std::string>  split  ( std::string& str, char split_char ) {

  const char*   cur = str.c_str();
  const char*   str_end = str.c_str() + str.size();
  std::vector<std::string>   tokens;

  while (cur < str_end)
  {
    const char*   start = cur;

    while ( start < str_end and *start == split_char )   start++;

    const char*   end = start + 1;

    while ( end < str_end and *end != split_char )   end++;

    cur = end + 1;

    tokens.push_back( std::string( start, end - start ) );

  }

  return tokens;

}

void  obj_parser  ( char* obj_src, std::vector<float>& v, std::vector<float>& vt, std::vector<float>& vn, std::vector<unsigned int>& f ){

    std::stringstream ss( obj_src );
    std::string tmp;
    std::vector<std::string> tokens;
    std::vector<std::string> tokens_f;

    while ( std::getline( ss, tmp, '\n' ) ){

        tokens = split( tmp, ' ' );

        if ( tokens[0] == "v" ){

            v.push_back ( std::stof( tokens[1] ));
            v.push_back ( std::stof( tokens[2] ));
            v.push_back ( std::stof( tokens[3] ));

        }

        if ( tokens[0] == "vt" ){

            vt.push_back ( std::stof( tokens[1] ));
            vt.push_back ( std::stof( tokens[2] ));

        }

        if ( tokens[0] == "vn" ){

            vn.push_back ( std::stof( tokens[1] ));
            vn.push_back ( std::stof( tokens[2] ));
            vn.push_back ( std::stof( tokens[3] ));

        }

        if ( tokens[0] == "f" ){

            for ( int i = 1; i < tokens.size(); i++ ){
                tokens_f = split( tokens[i], '/' );
                f.push_back( std::stoi( tokens_f[0]) - 1 );

                tokens_f.clear();
                tokens_f.shrink_to_fit();

            }

        }

        tokens.clear();
        tokens.shrink_to_fit();

    }

    std::cout << "V : " << std::endl;
    for(int i = 0; i < v.size(); i++) { std::cout << v[i] << " "; }

    std::cout << std::endl;

    std::cout << "VT : " << std::endl;
    for(int i = 0; i < vt.size(); i++) { std::cout << vt[i] << " "; }

    std::cout << std::endl;

    std::cout << "VN : " << std::endl;
    for(int i = 0; i < vn.size(); i++) { std::cout << vn[i] << " "; }

    std::cout << std::endl;

    std::cout << "F : " << std::endl;
    for(int i = 0; i < f.size(); i++) { std::cout << f[i] << " "; }

    std::cout << std::endl;

    std::cout << "Parse obj is done\n" << std::endl;
    
}   