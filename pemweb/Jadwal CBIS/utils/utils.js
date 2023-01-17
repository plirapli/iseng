const domParser = (text) => {
  const parser = new DOMParser();
  return parser.parseFromString(text, 'text/html');
};

export { domParser };
