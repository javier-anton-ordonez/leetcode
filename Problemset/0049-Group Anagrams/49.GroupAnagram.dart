List<List<String>> groupAnagrams(List<String> strs) {
  List<List<String>> listareturn = [];
  List<String> strsordenada = List.from(strs);

  // Ordenar las letras de cada palabra
  for (int i = 0; i < strsordenada.length; i++) {
    List<String> letras = strsordenada[i].split('');
    letras.sort();
    strsordenada[i] = letras.join('');
  }

  List<bool> usada = List.filled(strs.length, false);

  for (int i = 0; i < strs.length; i++) {
    if (usada[i]) continue;

    // Crear nuevo grupo
    listareturn.add([strs[i]]);
    usada[i] = true;

    // Buscar anagramas de strs[i]
    for (int j = i + 1; j < strs.length; j++) {
      if (!usada[j] && strsordenada[i] == strsordenada[j]) {
        listareturn.last.add(strs[j]);
        usada[j] = true;
      }
    }
  }

  return listareturn;
}

void main() {
  List<String> lista = ["eat", "tea", "tan", "ate", "nat", "bat"];
  List<List<String>> retorno = groupAnagrams(lista);
  print(retorno);
}
