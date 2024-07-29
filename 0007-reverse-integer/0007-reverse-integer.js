/**
 * @param {number} x
 * @return {number}
 */
var reverse = function (x) {
    let sign = '+';
    const strArray = x.toString().split('');
    if (strArray[0] === '-') {
        sign = '-';
        strArray.shift();
    }

    const str = parseInt(strArray.reverse().join(''));
    if (str > Math.pow(2, 31)) return 0;

    if (sign === '-') {
        return -str;
    }
    return str;
};