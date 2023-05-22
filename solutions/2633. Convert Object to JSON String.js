/**
 * @param {any} object
 * @return {string}
 */


// Approach 1: Using JSON-like String Concatenation : 89

var jsonStringify1 = function(object) {
  if (object === null) {
    return 'null';
  }

  if (Array.isArray(object)) {
    const elements = object.map((element) => jsonStringify(element));
    return `[${elements.join(',')}]`;
  }

  if (typeof object === 'object') {
    const keys = Object.keys(object);
    const keyValuePairs = keys.map((key) => `"${key}":${jsonStringify(object[key])}`);
    return `{${keyValuePairs.join(',')}}`;
  }

  if (typeof object === 'string') {
    return `"${object}"`;
  }

  return String(object);
};

//  Approach 2: Using Switch Case

var jsonStringify = function(object) {
  switch (typeof object) {
    case 'object':
      if (Array.isArray(object)) {
        const elements = object.map((element) => jsonStringify(element));
        return `[${elements.join(',')}]`;
      } else if (object) {
        const keys = Object.keys(object);
        const keyValuePairs = keys.map((key) => `"${key}":${jsonStringify(object[key])}`);
        return `{${keyValuePairs.join(',')}}`;
      } else {
        return 'null';
      }
    case 'boolean':
    case 'number':
      return `${object}`;
    case 'string':
      return `"${object}"`;
    default:
      return '';
  }
};
