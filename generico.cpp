#include <iostream>
#include <vector>
#include <functional>

template <typename T>
std::vector<T> processarVetor(const std::vector<T>& vetor, std::function<T(T)> funcao) {
    std::vector<T> resultado;
    for (const auto& item : vetor) {
        resultado.push_back(funcao(item));
    }
    return resultado;
}

// Exemplo de uso
int main() {
    // Vetor de inteiros
    std::vector<int> numeros = {1, 2, 3, 4, 5};
    
    // Função para dobrar um número
    auto dobrar = [](int x) { return x * 2; };
    
    std::vector<int> resultadoNumeros = processarVetor(numeros, dobrar);
    std::cout << "Resultado dos números dobrados: ";
    for (const auto& num : resultadoNumeros) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Vetor de strings
    std::vector<std::string> palavras = {"a", "b", "c"};
    
    // Função para converter para maiúsculas
    auto paraMaiusculas = [](const std::string& s) {
        std::string resultado = s;
        for (auto& c : resultado) {
            c = toupper(c);
        }
        return resultado;
    };
    
    std::vector<std::string> resultadoPalavras = processarVetor(palavras, paraMaiusculas);
    std::cout << "Resultado das palavras em maiúsculas: ";
    for (const auto& palavra : resultadoPalavras) {
        std::cout << palavra << " ";
    }
    std::cout << std::endl;

    return 0;
}
