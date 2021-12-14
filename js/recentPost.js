const datas = [
  {
    id: 1,
    title: "lorem ipsum",
    date: "01-01-2020"
  },
  {
    id: 2,
    title: "lorem ipsum",
    date: "21-05-2020"
  },
  {
    id: 3,
    title: "lorem ipsum",
    date: "11-11-2021"
  },
  {
    id: 4,
    title: "lorem ipsum",
    date: "15-10-2000"
  }
]

const recentPost = (datas) => {
  const newDataDateFormat = datas.map(data =>{
    const arrDate = data.date.split("-")
    const newDateFormat = new Date(arrDate[2], arrDate[1] - 1, arrDate[0]).toDateString()
    return data = {...data, date: newDateFormat}
  })

  return newDataDateFormat.sort((a, b) => {
    return new Date(b.date) - new Date(a.date)
  })
}

console.log(recentPost(datas))