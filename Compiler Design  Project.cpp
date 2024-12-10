#include <bits/stdc++.h>
using namespace std;

void showWelcome() {
    cout << "\t\t\t\t\t\t----------------------------------------------------\n\n";
    cout << "\t\t\t\t\t\t\t    Welcome to Mini Compiler\n\n";
    cout << "\t\t\t\t\t\t\t        HAPPY Compiling\n\n";
    cout << "\t\t\t\t\t\t----------------------------------------------------\n\n";
    cout << "\t\t\t\t\t\t\tPresented by,\n";
    cout << "\t\t\t\t\t\t\tMd. Abdul Rabbi Rahat 213-15-4583\n";
    cout << "\t\t\t\t\t\t\tMehedi Hasan Salman 213-15-4523\n\n";
}

void showMenu(){
    cout << "\nSelect an option:\n";
    cout << "1. Concatenate Strings\n";
    cout << "2. Count Characters, Words, Lines (Command Prompt Input)\n";
    cout << "3. Count Characters, Words, Lines (File Input)\n";
    cout << "4. Validate 'a+' Pattern\n";
    cout << "5. Validate 'a*b' Pattern\n";
    cout << "6. Validate 'a*b' Pattern (File Input)\n";
    cout << "7. Remove White Spaces from a String\n";
    cout << "8. Count Vowels, Consonants, and Digits\n";
    cout << "9. Tokenize String (Without strtok())\n";
    cout << "10. Tokenize String (Using strtok())\n";
    cout << "11. Remove Special Characters from String\n";
    cout << "12. Count Articles in a String\n";
    cout << "13. Identify Comments in Multi-line Input\n";
    cout << "14. Display Syntax Table (Letters, Digits, Symbols, Operators)\n";
    cout << "15. Check Keyword or Valid Identifier\n";
    cout << "16. Build a Lexical Analyzer\n";
    cout << "17. Remove Single and Multi-line Comments\n";
    cout << "18. Simple Symbol Table Implementation\n";
    cout << "19. Intermediate Code Generation\n";
    cout << "20. Exit\n";
}

void concatenateStrings() {
    string str1, str2;
    cout << "Enter String 1: ";
    cin.ignore();
    getline(cin, str1);
    cout << "Enter String 2: ";
    getline(cin, str2);

    string concatenated = str1 + str2;
    cout << "Output:\n" << concatenated << endl << endl;
}

void countCharsWordsLinesCMD() {
    char ch;
    int charCount = 0, lineCount = 0, wordCount = 0;
    bool inWord = false;

    cout << "Enter your text (press Ctrl+D or Ctrl+Z to end input):\n";
    while ((ch = getchar()) != EOF) {
        if (ch == '\n') {
            lineCount++;
        }

        if (ch != ' ' && ch != '\t' && ch != '\n') {
            charCount++;
        }

        if (ch == ' ' || ch == '\t' || ch == '\n') {
            inWord = false;
        } else if (!inWord) {
            inWord = true;
            wordCount++;
        }
    }

    cout << "\nCharacter Count: " << charCount << endl;
    cout << "Word Count: " << wordCount << endl;
    cout << "Line Count: " << lineCount << endl <<endl;
}

int countCharsWordsLinesInFiles() {
    FILE *file;
	char filename[100];
	char ch;
	int charCount = 0, lineCount = 0, wordCount = 0;
	bool inWord = false;

	cout << "Enter the Filename: ";
	cin >> filename;

	file = fopen(filename, "r");
	if (file == NULL) {
    	cout << "Could not open file" << endl;
    	return 1;
	}

	while ((ch = fgetc(file)) != EOF) {
    	if (ch == '\n') {
        	lineCount++;
    	}

    	if (ch != ' ' && ch != '\t' && ch != '\n') {
        	charCount++;
    	}

    	if (ch == ' ' || ch == '\t' || ch == '\n') {
        	inWord = false;
    	} else if (!inWord) {
        	inWord = true;
        	wordCount++;
    	}
	}

	if (charCount > 0 && ch != '\n') {
    	lineCount++;
	}

	fclose(file);

	cout << "\nCharacter Count: " << charCount << endl;
	cout << "Word Count: " << wordCount << endl;
	cout << "Line Count: " << lineCount << endl << endl;
}

int validateaExpression(){
    while(1)
	{
    	string str;
    	cout << "Enter the input string: ";
    	cin >> str;

    	for (char c : str)
    	{
        	if (c != 'a')
        	{
            	cout << "Rejected" << endl << endl;
            	return 0;
        	}
    	}
    	cout << "Accepted" << endl << endl;
	}

}

int validateaExpression2(){
    while(1)
	{
    	string str;
    	cout << "Enter the input string: ";
    	cin >> str;
    	int b_count = 0;
    	for (char c : str)
    	{
        	if (c == 'b')
        	{
            	b_count++;
        	}
        	else if (c != 'a')
        	{
            	cout << "Rejected" << endl << endl;
            	return 0;
        	}
    	}
    	if (b_count == 1 && str.back() == 'b')   //if the last character
    	{
        	                                   //of the string is 'b'
        	cout << "Accepted" << endl <<endl;
    	}
    	else
    	{
        	cout << "Rejected" << endl << endl;
        	return 0;
    	}
	}

}

int validateaExpression2InFiles(){
    FILE *file;
	char filename[100];
	char line[200];
	string str;
	cout << "Enter the filename: ";
	cin >> filename;

	file = fopen(filename, "r");
	if (file == NULL)
	{
    	cout << "Could not open file" << endl;
    	return 1;
	}
	while (fgets(line, sizeof(line), file))
	{
    	str = line;
    	// Remove the newline character if present
    	size_t newline_pos = str.find('\n');
    	if (newline_pos != string::npos)
    	{
        	str.erase(newline_pos);
    	}
    	int b_count = 0;
    	for (char c : str)
    	{
        	if (c == 'b')
        	{
            	b_count++;
        	}
        	else if (c != 'a')
        	{
            	cout << "Rejected" << endl;
            	fclose(file);
            	return 0;
        	}
    	}
    	if (b_count == 1 && str.back() == 'b')
    	{
        	cout << "Accepted" << endl;
    	}
    	else
    	{
        	cout << "Rejected" << endl <<endl;
    	}
	}
	fclose(file);
}

void removeWhiteSpace(){
    string str, output = "";
	cout << "Enter a string: ";
	cin.ignore();
	getline(cin, str);

	for(int i = 0; i < str.length(); i++)
	{
    	if(str[i] != ' ')
    	{
        	output += str[i];
    	}
	}
	cout << endl <<"String without spaces: " << output << endl <<endl;

}

void countVowelsConstantsDigits(){
    string str;
	int vowels = 0, consonants = 0, digits = 0;

	cout << "Enter a string: ";
	cin.ignore();
	getline(cin, str);

	for (int i = 0; i < str.length(); i++)
	{
    	char ch = str[i];

    	if (ch >= '0' && ch <= '9')
    	{
        	digits++;
    	}
    	else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    	{
    	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch
    	== 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O'
    	|| ch == 'U')
        	{
            	vowels++;
        	}
        	else
        	{
            	consonants++;
        	}
    	}
	}
    cout<< endl << "Output: " << endl;
	cout << "No of vowels: " << vowels << endl;
	cout << "No of consonants: " << consonants << endl;
	cout << "No of digits: " << digits << endl << endl;

}

void tokenizeStringWithoutStrtok(){
    char str[200];
	char tokens[50][50];
	int tokenCount = 0;
	int charIndex = 0;

	cout << "Enter a string: ";
	cin.ignore();
	cin.getline(str, 200);

	for (int i = 0; i <= strlen(str); i++) {
    	if (str[i] == ' ' || str[i] == '\0') {
        	tokens[tokenCount][charIndex] = '\0';
        	tokenCount++;
        	charIndex = 0;
    	} else {
        	tokens[tokenCount][charIndex++] = str[i];
    	}
	}
	cout << endl << "Tokenize String : " << endl;
	for (int i = 0; i < tokenCount; i++) {
    	cout << tokens[i] << endl;
	}
    cout<<endl;
}

void tokenizeStringWithStrtok(){
    string s;
	cout << "Enter a string: ";
	cin.ignore();
	getline(cin, s);

	// Convert the string to a C-style string for strtok
	char str[s.length() + 1];
	strcpy(str, s.c_str());

	// Tokenize the string using strtok() based on space
	char* token = strtok(str, " ");
    cout << endl << "Tokenize String : "<<endl;

	while (token != NULL)
	{
    	cout << token << endl;
    	token = strtok(NULL, " ");  // Get the next token
	}
    cout<<endl;
}

void removeSpecialChar(){
    string s, output;

	cout << "Enter a string: ";
	cin >> s;

	for (char ch : s) {
    	if (isalnum(ch)) {
        	output += ch;
    	}
	}

	cout << "String without special characters: " << output << endl <<endl;
}

void countArticles(){
    string input;
	int countA = 0, countAn = 0, countThe = 0;

	cout << "Enter the input string: ";
	cin.ignore();
	getline(cin, input);

	transform(input.begin(), input.end(), input.begin(), ::tolower);

	istringstream stream(input);
	string word;

	while (stream >> word) {
    	if (word == "a") {
        	countA++;
    	} else if (word == "an") {
        	countAn++;
    	} else if (word == "the") {
        	countThe++;
    	}
	}

	cout << "Count of 'a': " << countA << endl;
	cout << "Count of 'an': " << countAn << endl;
	cout << "Count of 'the': " << countThe << endl << endl;

}

void identifyComments(){
    string str, comment;
	int S_F = 0, M_F = 0;
	char ch;

	cout << "Enter the input: " << endl;
	cin.ignore();
	while ((ch = getchar()) != EOF) {
    	str += ch;
	}

	for (int i = 0; i < str.length(); i++) {
    	if (S_F == 0 && M_F == 0) {
        	if (str[i] == '/' && str[i + 1] == '/') {
            	S_F = 1;
            	comment = "//";  // Start of single-line comment
            	i++;
        	} else if (str[i] == '/' && str[i + 1] == '*') {
            	M_F = 1;
            	comment = "/*";  // Start of multi-line comment
            	i++;
        	}
    	}

    	else if (S_F == 1) {
        	if (str[i] == '\n') {
            	S_F = 0;  // End of single-line comment
            	cout << endl << "Output : "<< endl;
            	cout << "Single-line comment: " << comment << endl;
            	comment = "";
        	} else {
            	comment += str[i];
        	}
    	}

    	else if (M_F == 1) {
        	comment += str[i];
        	if (str[i] == '*' && str[i + 1] == '/') {
            	M_F = 0;  // End of multi-line comment
            	comment += '/';
            	cout << "Multi-line comment: " << comment << endl << endl;
            	comment = "";
            	i++;
        	}
    	}
	}

	// Handle edge case for single-line comment at EOF
	if (S_F == 1) {
    	cout << "Single-line comment: " << comment << endl;
	}

}

void displaySyntaxTable(){
    string input;
	cout << "Enter a string: ";
	cin >> input;

	cout << "Letters: ";
	for (char c : input) {
    	if (isalpha(c)) cout << c;
	}
	cout << endl;

	cout << "Digits: ";
	for (char c : input) {
    	if (isdigit(c)) cout << c;
	}
	cout << endl;

	cout << "Arithmetic Operators: ";
	const string operators = "+-*/%=<>!&&||";
	for (char c : input) {
    	if (operators.find(c) != string::npos) {
        	cout << c << " ";
    	}
	}
	cout << endl;

	cout << "Special Characters: ";
	for (char c : input) {
    	if (!isalnum(c) && operators.find(c) == string::npos) {
        	cout << c << " ";
    	}
	}
	cout << endl;

	cout << "Logical Operators: ";
	if (input.find("&&") != string::npos) cout << "&& ";
	if (input.find("||") != string::npos) cout << "|| ";
	cout << endl;

	cout << "Relational Operators: ";
	const string relational[] = {"==", "!=", "<", ">", "<=", ">="};
	for (const string & op : relational) {
    	if (input.find(op) != string::npos) {
        	cout << op << " ";
    	}
	}
	cout << endl << endl;
}

void checkKeywordValid(){
    string input;
	char ch;

	cout << "Enter strings : " << endl;

	while (cin>>input) {
    	string keywords[] = {
        	"asm", "double", "new", "switch", "auto", "else", "operator", "template",
        	"break", "enum", "private", "this", "case", "extern", "protected", "throw",
        	"catch", "float", "public", "try", "char", "for", "register", "typedef",
        	"class", "friend", "return", "union", "const", "goto", "short", "unsigned",
        	"continue", "if", "signed", "virtual", "default", "inline", "sizeof", "void",
        	"delete", "int", "static", "volatile", "do", "long", "struct", "while"
    	};

    	bool isKeyword = false;
    	for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        	if (input == keywords[i]) {
            	isKeyword = true;
            	break;
        	}
    	}

    	if (isKeyword) {
        	cout << "Keyword" << endl << endl;
    	}

    	else if (isdigit(input[0])) {
        	cout << "Invalid identifier" << endl << endl;
        	break;
    	}

    	else {
        	bool isValid = true;
        	for (char c : input) {
            	if (!isalnum(c) && c != '_') {
                	isValid = false;
                	break;
            	}
        	}
        	if (isValid) {
            	cout << "Valid identifier" << endl << endl;
        	} else {
            	cout << "Invalid identifier" << endl << endl;
            	break;
        	}
    	}
	}
}

void lexicalAnalyzer(){
    string input;
    cin.ignore();
	cout << "Enter the input string: ";
	getline(cin, input);

	string keywords[] = {
    	"asm", "double", "new", "switch", "auto", "else", "operator", "template",
    	"break", "enum", "private", "this", "case", "extern", "protected", "throw",
    	"catch", "float", "public", "try", "char", "for", "register", "typedef",
    	"class", "friend", "return", "union", "const", "goto", "short", "unsigned",
    	"continue", "if", "signed", "virtual", "default", "inline", "sizeof", "void",
    	"delete", "int", "static", "volatile", "do", "long", "struct", "while", "string"
	};

	string keywordsOutput = "Keywords: ";
	string identifierOutput = "Identifier: ";
	string delimiterOutput = "Delimiter: ";
	string binaryOperatorOutput = "Binary Operator: ";
	string stringLiteralOutput = "String Literal: ";

	bool inStringLiteral = false;
	string currentToken = "";
	for (char c : input) {
    	if (inStringLiteral) {
        	if (c == '"') {
            	inStringLiteral = false;
            	stringLiteralOutput += "\"" + currentToken + "\" ";
            	currentToken = "";
        	} else {
            	currentToken += c;
        	}
    	} else {
        	if (c == '"') {
            	inStringLiteral = true;
        	} else if (isalnum(c) || c == '_') {
            	currentToken += c;
        	} else {
            	if (!currentToken.empty()) {
                	bool isKeyword = false;
                	for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
                    	if (currentToken == keywords[i]) {
                        	isKeyword = true;
                        	break;
                    	}
                	}
                	if (isKeyword) {
                    	keywordsOutput += currentToken + " ";
                	} else {
                    	identifierOutput += currentToken + " ";
                	}
                	currentToken = "";
            	}

            	if (c == ',' || c == ';') {
                	delimiterOutput += c;
                	delimiterOutput += " ";
            	} else if (c == '=' || c == '+' || c == '-' || c == '*' || c == '/') {
                	binaryOperatorOutput += c;
                	binaryOperatorOutput += " ";
            	}
        	}
    	}
	}

	cout << keywordsOutput << endl;
	cout << identifierOutput << endl;
	cout << delimiterOutput << endl;
	cout << binaryOperatorOutput << endl;
	cout << stringLiteralOutput << endl << endl;

}

void removeComments(){
    string str1, str2;
	int S_F = 0, M_F = 0;
	char ch;

	cout<<"Enter the String : "<<endl;
    cin.ignore();
	while ((ch = getchar()) != EOF)
	{
    	str1 += ch;
	}
	for (int i = 0; i < str1.length(); i++)
	{
    	if (S_F == 0 && M_F == 0)
    	{
        	if (str1[i] == '/' && str1[i + 1] == '/')
        	{
            	S_F = 1;
            	i++;
        	}
        	else if (str1[i] == '/' && str1[i + 1] == '*')
        	{
            	M_F = 1;
            	i++;
        	}
        	else
        	{
            	str2 += str1[i];
        	}
    	}
    	else if (S_F == 1)
    	{
        	if (str1[i] == '\n')
        	{
            	S_F = 0;
            	str2 += '\n';
        	}
    	}
    	else if (M_F == 1)
    	{
        	if (str1[i] == '*' && str1[i + 1] == '/')
        	{
            	M_F = 0;
            	i++;
        	}
    	}
	}
	cout <<"The output: " << endl << str2 << endl <<endl;

}

void symbolTableAttributes(){
    const int MAX_ENTRIES = 100;
	int serial[100];
	string name[100];
	string type[100];
	string scope[100];
	int count = 0, choice;

	while (true) {
    	cout << "\nSymbol Table Menu:\n";
    	cout << "1. Insert\n";
    	cout << "2. Display\n";
    	cout << "3. Exit\n";
    	cout << "Enter your choice: ";
    	cin >> choice;

    	if (choice == 1) {
        	if (count < MAX_ENTRIES) {
            	cout << "Enter serial number : ";
            	cin >> serial[count];
            	cout << "Enter variable name : ";
            	cin >> name[count];
            	cout << "Enter variable type : ";
            	cin >> type[count];
            	cout << "Enter scope : local/global : ";
            	cin >> scope[count];
            	count++;
            	cout << "Entry added successfully!\n";
        	} else {
            	cout << "Symbol table is full!\n";
        	}
    	} else if (choice == 2) {
        	if (count == 0) {
            	cout << "Symbol table is empty.\n";
        	} else {
            	cout << "Serial\tName\tType\tScope\n";
            	for (int i = 0; i < count; i++) {
                	cout << serial[i] << "\t" << name[i] << "\t" << type[i] << "\t" << scope[i] << endl;
            	}
        	}
    	} else if (choice == 3) {
        	cout << "Exiting program.\n";
        	break;
    	} else {
        	cout << "Invalid choice. Try again.\n";
    	}
	}
  cout<<endl;
}

void intermediateCodeGeneration(){
    string expression;
    cout << "Enter the postfix expression : ";
    cin >> expression;

    stack<string> s;
    int tempCount = 1;

    for (char ch : expression)
    {
        if (isalpha(ch))
        {
            s.push(string(1, ch));
        }
        else
        {
            string op2 = s.top();
            s.pop();
            string op1 = s.top();
            s.pop();

            cout << "t" << tempCount << " = " << op1 << " " << ch << " " << op2 << endl;
            s.push("t" + to_string(tempCount));
            tempCount++;
        }
    }
  cout<<endl;
}

int main() {
    int choice;
    char tryAgain;

    showWelcome();

    while (true) {
        showMenu();
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                concatenateStrings();
                break;
            case 2:
                countCharsWordsLinesCMD();
                break;
            case 3:
                countCharsWordsLinesInFiles();
                break;
            case 4:
                validateaExpression();
                break;
            case 5:
                validateaExpression2();
                break;
            case 6:
                validateaExpression2InFiles();
                break;
            case 7:
                removeWhiteSpace();
                break;
            case 8:
                countVowelsConstantsDigits();
                break;
            case 9:
                tokenizeStringWithoutStrtok();
                break;
            case 10:
                tokenizeStringWithStrtok();
                break;
            case 11:
                removeSpecialChar();
                break;
            case 12:
                countArticles();
                break;
            case 13:
                identifyComments();
                break;
            case 14:
                displaySyntaxTable();
                break;
            case 15:
                checkKeywordValid();
                break;
            case 16:
                lexicalAnalyzer();
                break;
            case 17:
                removeComments();
                break;
            case 18:
                symbolTableAttributes();
                break;
            case 19:
                intermediateCodeGeneration();
                break;
            case 20:
                cout << endl<< "Thank you for using Mini Compiler. Goodbye!" <<endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << "Would you like to try again our Mini Compiler? (y/n): ";
        cin >> tryAgain;

        if (tolower(tryAgain) != 'y') {
            cout << endl << "Thank you for using Mini Compiler. Goodbye!" <<endl;
            break;
        }
    }
    return 0;
}

//©This Project was done by Md. Abdul Rabbi Rahat & Mehedi Hasan Salman of Daffodil International University//
