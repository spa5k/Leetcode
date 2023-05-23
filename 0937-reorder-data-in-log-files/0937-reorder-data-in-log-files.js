/**
 * @param {string[]} logs
 * @return {string[]}
 */
var reorderLogFiles = function (logs) {
  const digitLogs = [];
  const letterLogs = [];

  for (const log of logs) {
    if (isDigitLog(log)) {
      digitLogs.push(log);
    } else {
      letterLogs.push(log);
    }
  }

  letterLogs.sort((a, b) => {
    const aStr = a.slice(a.indexOf(" ") + 1);
    const bStr = b.slice(b.indexOf(" ") + 1);

    if (aStr === bStr) {
      return a.localeCompare(b);
    } else {
      return aStr.localeCompare(bStr);
    }
  });
  return [...letterLogs, ...digitLogs];
};

const isDigitLog = (log) => {
  // remove first word
  const logBody = log.slice(log.indexOf(" ") + 1);
  // check if there is no letter
  return !/[a-zA-Z]/.test(logBody);
};


const isLetterLog = (log) => {
  if (log.startsWith("let")) {
    return true;
  }
};