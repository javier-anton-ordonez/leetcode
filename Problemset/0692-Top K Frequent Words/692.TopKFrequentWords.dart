List<String> topKFrequent(List<String> words, int k) {
  Map<String, int> cantidades={};
  
  words.sort();
  print(words);
  int i;
  for (i = 0; i<words.length;i++){
    cantidades[words[i]] = (cantidades[words[i]] ?? 0) + 1;
  }  
  var lista = cantidades.entries.toList();
  for (i = 0; i < lista.length - 1; i++) {
    for (int j = 0; j < lista.length - i - 1; j++) {
      if (lista[j].value < lista[j + 1].value) {
        // Intercambiar elementos
        var temp = lista[j];
        lista[j] = lista[j + 1];
        lista[j + 1] = temp;
      }
    }
  }
  List<String> listaReturn=[];
  for(i=0;i<k; i++){
    listaReturn.add(lista[i].key);
  }
  print(listaReturn);
  return words;
}

void main(List<String> args) {
  List<String> tabla = ["i","love","leetcode","i","love","coding"];  
  topKFrequent(tabla, 2); 
}
