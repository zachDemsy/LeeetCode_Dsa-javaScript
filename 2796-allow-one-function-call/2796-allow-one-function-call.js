/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function(fn) {
    let called = false;
    let result;

    return function(...args) {
        if (!called) {
            called = true;
            result = fn(...args);
            return result;
        } else {
            return undefined;
        }
    }
};

/**
 * Example usage:
 * let fn = (a, b, c) => (a + b + c);
 * let onceFn = once(fn);
 *
 * console.log(onceFn(1, 2, 3)); // 6
 * console.log(onceFn(2, 3, 6)); // undefined
 */
