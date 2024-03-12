// function countAnagrams(s1, s2) {
//   let umap = new Map();
//   //   for (let i = 0; i < s2.length; i++) {
//   //     if (umap.has(s2[i])) {
//   //       umap.set(s2[i], umap.get(s2[i]) + 1);
//   //     } else {
//   //       umap.set(s2[i], 1);
//   //     }
//   //   }
//   for (let i = 0; i < s2.length; i++) {
//     umap[s2[i]]++;
//   }

//   let i = 0;
//   let j = 0;
//   let count = umap.size;
//   let ans = 0;
//   let k = s2.length;

//   while (j < s1.length) {
//     if (umap.has(s1[j])) {
//       umap.set(s1[j], umap.get(s1[j]) - 1);
//       if (umap.get(s1[j]) === 0) {
//         count--;
//       }
//     }

//     if (j - i + 1 < k) {
//       j++;
//     } else if (j - i + 1 === k) {
//       if (count === 0) {
//         ans++;
//       }

//       if (umap.has(s1[i])) {
//         umap.set(s1[i], umap.get(s1[i]) + 1);
//         if (umap.get(s1[i]) === 1) {
//           count++;
//         }
//       }

//       i++;
//       j++;
//     }
//   }

//   return ans;
// }

// let s1 = "forxxofrcvfor";
// let s2 = "for";
// let ans = countAnagrams(s1, s2);
// console.log("The Total anagrams is " + ans);

function countAnagrams(s1, s2) {
  let umap = {};

  for (let i = 0; i < s2.length; i++) {
    // umap[s2[i]] = (umap[s2[i]] || 0) + 1;
    umap[s2[i]] = (umap[s2[i]] || 0) + 1;
  }

  let i = 0;
  let j = 0;
  let count = Object.keys(umap).length;
  let ans = 0;
  let k = s2.length;

  while (j < s1.length) {
    if (umap[s1[j]] !== undefined) {
      umap[s1[j]]--;
      if (umap[s1[j]] === 0) {
        count--;
      }
    }

    if (j - i + 1 < k) {
      j++;
    } else if (j - i + 1 === k) {
      if (count === 0) {
        ans++;
      }

      if (umap[s1[i]] !== undefined) {
        umap[s1[i]]++;
        if (umap[s1[i]] === 1) {
          count++;
        }
      }

      i++;
      j++;
    }
  }

  return ans;
}

let s1 = "forxxofrcvfor";
let s2 = "for";
let ans = countAnagrams(s1, s2);
console.log("The Total anagrams is " + ans);
