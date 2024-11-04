function compressedString(word: string): string {
  let comp = [];
  let n = word.length;
  let count = 1;

  for (let i = 1; i <= n; i++) {
    // check if the word is out of bound or not equal to prev or count == 9 then we push
    if (i == n || word[i] != word[i - 1] || count == 9) {
      comp.push(count + word[i - 1]);

      // reset the freq to 1
      count = 1;
    } else {
      count++;
    }
  }

  return comp.join('');
}
