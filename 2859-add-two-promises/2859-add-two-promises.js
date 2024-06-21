/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
    // Await both promises to get their resolved values
    const value1 = await promise1;
    const value2 = await promise2;
    
    // Return the sum of the resolved values
    return value1 + value2;
};

/**
 * Example usage:
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */
