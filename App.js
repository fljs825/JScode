/* eslint-disable */

import React, { useState, useEffect } from 'react';
import './App.css';
import { openFile, draw, settings } from '../node_modules/jsroot/modules/main.mjs';
import image_cat from './cat.png';

function App() {

    settings.useStamp = false;
    
    let [title, title_ch] = useState(['blah1', 'blah2', 'blah3']);
    let mainfont = { color : 'white', fontSize : '30px' };
    let [compo, compo_ch] = useState(false);
    let [detail1, setdetail1] = useState('detail');
    
    let [like_num, like_num_ch] = useState(0);

    async function fetchData() {
        try {
          let file = await openFile("./histo_dt_4000.root");
          let obj = await file.readObject('h2;1');
          draw('drawing', obj, 'colz');
        } catch (error) {
          console.error('Error fetching data:', error);
        }
    }
    
    useEffect(() => {
      fetchData();
      // Cleanup function (optional)
      return () => {
        // Cleanup logic (if needed)
      };
    }, []);

    function section_ch(){
        var newArr = [...title];
        newArr[0] = 'blah_extra';
        title_ch( newArr );
    }
    
    function section_pre(){
        var newArr2 = [...title];
        newArr2[0] = 'blah1';
        title_ch( newArr2 );
    }

  return (
    <div className="App">
        <div className="black-nav">
          <div style={ mainfont }>
          
          <a href="index.html" className="homepage"> 
          <img src={ image_cat }
          alt='cat'
          style={ { height : "40px" } }
          />
          SUBMET Analysis_proto</a>
  
          </div>
        </div>
          
          <nav>
              <h2>Welcome!</h2>
              <h3>Contents</h3>
              <ul>
                  <li>
                      <a href="index.html"><p>Basic Calculator</p></a>
          
                      <a href="index.html"><p>Matrix Mutlplier</p></a>
                </li>
            </ul>
        </nav>
        
        <div className="mainbody">
          <button onClick={ section_pre }>Previous</button>
          <button onClick={ section_ch }>Next</button>
          
          <div className="menubox">
          <Menu menu_name="Data Taking" menu_image={image_cat}/>
          <a href="data_taking.html" className='menubox_href'>
          <Menu menu_name="Data Analysis" menu_image={image_cat}/>
          </a>
          <Menu menu_name="Manual" menu_image={image_cat}/>
          <Menu menu_name="Library" menu_image={image_cat}/>
          </div>
          
        <div className="list">
          <h3>My first react proejct</h3>
          <p>Feb 7, 2024</p>
          <hr/>
        </div>
        
        <div className="list">
          <h3> { title[0] } <span onClick={ ()=>{ like_num_ch(like_num + 1) } }>🧡</span> { like_num } </h3>
          <p>Feb 7, 2024</p>
          <hr/>
        </div>
          
        <div className="list">
          <h3>{ title[1] } <span onClick= { ()=> { compo_ch(!compo)}}> { compo ? "hold up" : "details" }</span>

              </h3>
          <p>Feb 7, 2024</p>
          <hr/>

        </div>
          {compo && <Modal onClose={()=>compo_ch(false)} />}
          <div id="drawing" style={{ width: '600px', height: '400px' }} />
          <div className="contact_info">
            <h3>produced by KU HEPEX</h3>
          </div>
          </div>


    </div>
  );
}

function Modal({ onClose }){
    return (
            <div className="modal">
              <h2>Title</h2>
              <p>Date : </p>
              <p>Details : </p>
            <button onClick={ onClose }>Hold up</button>
            </div>
            );
}

function Menu({ menu_name, menu_image }) {
    return (
            <div className="menu">
            <h2>{ menu_name }</h2>
            <img src={ menu_image }
            style={ { height : "40px" } }
            />
            </div>
            )
}

export default App;
